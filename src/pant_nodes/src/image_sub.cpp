#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include <opencv2/opencv.hpp>

class ImageSubscriber : public rclcpp::Node
{
public:
  ImageSubscriber() : Node("image_subscriber")
  {
    subscription_ = this->create_subscription<sensor_msgs::msg::Image>(
      "color_image",
      1,
      std::bind(&ImageSubscriber::imageCallback, this, std::placeholders::_1)
    );
  }

private:
  void imageCallback(const sensor_msgs::msg::Image::SharedPtr msg)
  {
    cv::Mat image(
      msg->height,
      msg->width,
      CV_MAKETYPE(CV_8U, msg->step / msg->width),
      const_cast<unsigned char*>(msg->data.data()),
      msg->step
    );

    cv::imshow("Image", image);
    cv::waitKey(1);
  }

  rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscription_;
};

int main(int argc, char* argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ImageSubscriber>());
  rclcpp::shutdown();
  return 0;
}
