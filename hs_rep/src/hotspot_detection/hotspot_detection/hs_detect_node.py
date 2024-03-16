#!/usr/bin/env python3

import rclpy
import cv2
import numpy as np
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge



class MinimalSubscriber(Node):

    def __init__(self):
        super().__init__('minimal_subscriber')

        # Subscribe to /image_raw topic
        self.subscription = self.create_subscription(Image, '/image_raw', self.image_callback, 10)
        self.subscription  # Prevent unused variable warning
        self.bridge = CvBridge()

    def image_callback(self, msg):
        try:
            # Convert ROS 2 Image message to OpenCV format
            self.cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")

            # Region of Interest (ROI) to limit area hotspot detection works in
            self.y1 = 55
            self.y2 = 425
            self.x1 = 0
            self.x2 = 540
            self.imROI = self.cv_image[self.y1:self.y2, self.x1:self.x2]

            # Erosion
            self.padded_image = cv2.copyMakeBorder(self.imROI, top=54, bottom=54,
                                                   left=0, right=0, borderType=cv2.BORDER_CONSTANT, value=0)
            kernel = np.ones((3,3), np.uint8)
            self.erosion_image = cv2.erode(self.padded_image, kernel, iterations=1)
            self.dilated_image = cv2.dilate(self.padded_image, kernel, iterations=1)
            self.ed_image = cv2.dilate(self.erosion_image, kernel, iterations=1)


           # Call hotspot detection function
            MinimalSubscriber.hotspot_detection(self)

        # Error handling
        except Exception as e:
            self.get_logger().error(f"Error processing image: {str(e)}")

    def hotspot_detection(self):

        # Find the maximum pixel intensity value (brightest point)
        max_intensity = np.max(self.erosion_image)
        max_intensity_location = np.where(self.erosion_image == max_intensity)

        # Get the coordinates of the brightest point
        x, y = max_intensity_location[1][0], max_intensity_location[0][0]

        # Draw an outer circle (red ring) around the brightest point
        inner_circle_radius = 10
        outer_circle_radius = inner_circle_radius + 3  # Slightly larger radius
        circle_color = (0, 0, 255)  # Red color
        cv2.circle(self.cv_image, (x, y), outer_circle_radius, circle_color, 2)
        cv2.circle(self.erosion_image, (x, y), outer_circle_radius, circle_color, 2)

        # Draw rectangle for ROI (Optional)
        cv2.rectangle(self.cv_image, (self.x1, self.y1), (self.x2, self.y2), (255, 0, 0), 2)
        cv2.rectangle(self.erosion_image, (self.x1, self.y1), (self.x2, self.y2), (255, 0, 0), 2)

        print(f"Circle drawn around the brightest point at ({x}, {y}).")
        self.measurement_point = 2
        output_image_path = f"{str(self.measurement_point)} hotspot.jpg"
        print(f"Modified image saved as '{output_image_path}'")
        cv2.imwrite(output_image_path, self.cv_image)
        cv2.imwrite("eroded image.jpg", self.erosion_image)
        cv2.imwrite("dilated image.jpg", self.dilated_image)
        cv2.imwrite("ed image.jpg", self.ed_image)
        #cv2.imshow('Eroded image', self.ersion_image)
        #cv2.waitKey(0)
        


def main(args=None):
    rclpy.init(args=args)

    minimal_subscriber = MinimalSubscriber()
    rclpy.spin_once(minimal_subscriber)

    rclpy.shutdown()

if __name__ == '__main__':
    main()

