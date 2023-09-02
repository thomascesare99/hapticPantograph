#include "rclcpp/rclcpp.hpp"
#include <memory>
#include <chrono>
#include "sensor_msgs/msg/image.hpp"

#include <iostream> // for standard I/O
#include <string> // for strings
#include <iomanip> // for controlling float print precision
#include <sstream> // string to number conversion
#include <opencv2/core.hpp> // Basic OpenCV structures (cv::Mat, Scalar)
#include <opencv2/imgproc.hpp> // Gaussian Blur
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp> // OpenCV window I/O

using namespace std;
using namespace cv; 

class AstraNode : public rclcpp::Node
{
  public:
    AstraNode(): Node("astra_node")
    {
      image_publisher_ = this->create_publisher<sensor_msgs::msg::Image>("color_image", 1);

      captRefrnc_.open(2);
      if (!captRefrnc_.isOpened()) {
          RCLCPP_ERROR(this->get_logger(), "Could not open reference");
          throw std::runtime_error("could not open rederence");
      }

      timer_ = create_wall_timer(std::chrono::milliseconds(30), [this]() {publishFrame(); });
    }

  private:
    void publishFrame()
    {
      cv::Mat frameReference;
      captRefrnc_ >> frameReference;
      if (frameReference.empty())
        {
          RCLCPP_INFO(this->get_logger(), "Empty frame");
          rclcpp::shutdown();
          return;
        }

      // Create an image message
      auto image_msg = std::make_shared<sensor_msgs::msg::Image>();
      image_msg->header.stamp = this->now();
      image_msg->header.frame_id = "camera_frame";
      image_msg->height = frameReference.rows;
      image_msg->width = frameReference.cols;
      image_msg->encoding = "bgr8";
      image_msg->step = frameReference.cols * frameReference.elemSize();
      size_t size = frameReference.total() * frameReference.elemSize();
      image_msg->data.resize(size);
      memcpy(&image_msg->data[0], frameReference.data, size);

      // Publish the image message
      image_publisher_->publish(*image_msg);
    }
  
  cv::VideoCapture captRefrnc_;
  rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr image_publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<AstraNode>());
  rclcpp::shutdown();
  return 0;
}