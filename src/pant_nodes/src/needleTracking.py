#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
import yaml
import pickle

import cv2
import numpy as np
from collections import deque
from sensor_msgs.msg import Image
from std_msgs.msg import Float32

class needleTracker(Node):
    def __init__(self):
        super().__init__('needle_tracker')
        self.image_publisher_ = self.create_publisher(Image, 'color_image', 1)
        self.distance_publisher_ = self.create_publisher(Float32, 'centroids_distance', 1)
        self.cap = cv2.VideoCapture(2)
        self.sensitivity = 15
        self.num_frames_to_average = 10
        self.centroids_buffer = deque(maxlen=self.num_frames_to_average)
        self.run()        
    
    def publish_image(self, cv_image):
        # Create a sensor_msgs.msg.Image message
        msg = Image()
        msg.header.frame_id = 'camera_frame'
        msg.height = cv_image.shape[0]
        msg.width = cv_image.shape[1]
        msg.encoding = 'bgr8'
        msg.is_bigendian = False
        msg.step = cv_image.shape[1] * 3
        msg.data = cv_image.tobytes()

        self.image_publisher_.publish(msg)

    def run(self):
        with open("src/pant_nodes/gui_config.yaml", 'r') as f:
            config_data = yaml.safe_load(f)
        pickle_path = config_data['pickle_path']

        with open(pickle_path, 'rb') as f:
            pickle_data = pickle.load(f)
        self.cameraMatrix = pickle_data[0]
        print("CamMatrix", self.cameraMatrix)
        self.distCoeff = pickle_data[1]
        # print(self.distCoeff)
        focal_length = np.mean((self.cameraMatrix[0,0], self.cameraMatrix[1,1]), axis=0)
        print("f:", focal_length)

        while True:
            _, frame = self.cap.read()
            hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

            lower = np.array([0, 0, 0])
            upper = np.array([self.sensitivity, 255-self.sensitivity, 255])  

            mask = cv2.inRange(hsv, lower, upper)
            kernel = np.ones((4,4), np.uint8)
            mask = cv2.erode(mask, kernel)

            contours, _ = cv2.findContours(mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
            biggest_contours = sorted(contours, key=cv2.contourArea, reverse=True)[:2]
            centroids = []

            # for every contour extract the centroid and append it to centroids (in the current frame)
            for cnt in biggest_contours:
                # Calculate the moments of the contour
                M = cv2.moments(cnt)
                # Calculate the centroid (central point) of the contour
                if M["m00"] != 0:
                    cx = int(M["m10"] / M["m00"])
                    cy = int(M["m01"] / M["m00"])
                    centroids.append((cx, cy))
            
            if len(centroids)==2:
                if self.centroids_buffer: # if there was already something in the buffer compare the current frame centroids with the previous
                    prev_centroids = self.centroids_buffer[-1]
                    # compute the distances between the first centroid of the current frame and the two centroids of the previous frame
                    distances = [np.linalg.norm(np.array(centroids[0]) - np.array(pc)) for pc in prev_centroids]

                    nearest_centroid = centroids[np.argmin(distances)]
                    furthest_centroid = centroids[np.argmax(distances)]
                    self.centroids_buffer.append((nearest_centroid, furthest_centroid))
                else:
                # If no centroids in buffer, just add the current centroids
                    self.centroids_buffer.append(centroids)
            else: 
                print("found only .{} centroid", len(centroids) )

            if len(self.centroids_buffer)==self.num_frames_to_average: # when buffer is full
                # print(self.centroids_buffer)
                avg_centroids = np.mean(self.centroids_buffer, axis=0, dtype=np.float32)
                for avg_centroid in avg_centroids:
                    cv2.circle(frame, avg_centroid.astype(np.uint32), 5, (0, 0, 255), -1)

                # undistorted_centroids = cv2.undistortPoints(avg_centroids.astype(np.float32), self.cameraMatrix, self.distCoeff)
                # print("Undistorted centroids:", undistorted_centroids)
                # print( np.vstack((avg_centroids.T, np.ones((1, 2)))))
                # points_in_image_plane = np.dot(np.linalg.inv(self.cameraMatrix), np.vstack((avg_centroids.T, np.ones((1, 2)))))
                # points_in_image_plane = points_in_image_plane[:2] / points_in_image_plane[2]
                # print("pts_in_img_plane: ", points_in_image_plane)
                # centroid_distance = np.linalg.norm(np.array(points_in_image_plane[0] - points_in_image_plane[1]))
                print("centroid0: ", avg_centroids[0])
                print("centroids1: ", avg_centroids[1])
                print("difference: ", (avg_centroids[0] - [avg_centroids[1]]))
                distance_in_px = np.linalg.norm(avg_centroids[0] - avg_centroids[1])
                print("d:", distance_in_px)

                centroid_distance = distance_in_px / focal_length

                dist_msg = Float32()
                dist_msg.data = centroid_distance
                self.distance_publisher_.publish(dist_msg)

            self.publish_image(frame)
            # print("Published frame")


def main(args=None):
    rclpy.init(args=args)
    needle_tracker_node = needleTracker()
    rclpy.spin(needle_tracker_node)
    needle_tracker_node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
