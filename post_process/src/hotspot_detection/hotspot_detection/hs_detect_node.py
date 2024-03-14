#!/usr/bin/env python3

import rclpy
import cv2
import numpy as np
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge



class MinimalSubscriber(Node):

    def __init__(self):
        self.timer = 0
        super().__init__('minimal_subscriber')

        # Subscribe to /image_raw topic
        self.subscription = self.create_subscription(Image, '/image_raw', self.image_callback, 10)
        self.subscription  # Prevent unused variable warning
        self.bridge = CvBridge()

    def image_callback(self, msg):
        try:
            # Convert ROS 2 Image message to OpenCV format
            self.cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")

           # Call hotspot detection function
            MinimalSubscriber.hotspot_detection(self)

        # Error handling
        except Exception as e:
            self.get_logger().error(f"Error processing image: {str(e)}")

    def hotspot_detection(self):

        # Find the maximum pixel intensity value (brightest point)
        max_intensity = np.max(self.cv_image)
        max_intensity_location = np.where(self.cv_image == max_intensity)

        # Get the coordinates of the brightest point
        x, y = max_intensity_location[1][0], max_intensity_location[0][0]

        # Draw an outer circle (red ring) around the brightest point
        inner_circle_radius = 10
        outer_circle_radius = inner_circle_radius + 3  # Slightly larger radius
        circle_color = (0, 0, 255)  # Red color
        cv2.circle(self.cv_image, (x, y), outer_circle_radius, circle_color, 2)  # Thickness = 1

        print(f"Circle drawn around the brightest point at ({x}, {y}).")
        self.timer = self.timer + 1
        output_image_path = f"test {str(self.timer)} hotspot.jpg"
        print(f"Modified image saved as '{output_image_path}'")
        cv2.imwrite(output_image_path, self.cv_image)



def main(args=None):
    rclpy.init(args=args)

    minimal_subscriber = MinimalSubscriber()
    rclpy.spin(minimal_subscriber)

    rclpy.shutdown()

if __name__ == '__main__':
    main()

