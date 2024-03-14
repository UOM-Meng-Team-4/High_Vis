#!/usr/bin/env python3

import rclpy
import cv2
import numpy as np
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge

timer = 0

class MinimalSubscriber(Node):
    timer = timer +1
    def __init__(self):
        print("2")
        super().__init__('minimal_subscriber')

        # Subscribe to /image_raw topic
        self.subscription = self.create_subscription(Image, '/image_raw', self.image_callback, 10)
        self.subscription  # Prevent unused variable warning
        self.bridge = CvBridge()

    def image_callback(self, msg):
        print("3")
        try:
            # Convert ROS 2 Image message to OpenCV format
            self.cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")
            print("3a")
            # Process the image (e.g., display it, save it, etc.)
            # For demonstration purposes, let's display the image
            #cv2.imshow("Received Image", cv_image)
            #cv2.waitKey(1)  # Wait for a key press (optional)
            MinimalSubscriber.hotspot_detection(self)

        # Error handling
        except Exception as e:
            self.get_logger().error(f"Error processing image: {str(e)}")
            print("3b")

    def hotspot_detection(self):
        print("4")
        self.gray_image = cv2.imread(self.cv_image, cv2.IMREAD_GRAYSCALE)
        self.colour_image = cv2.cvtColor(gray_image, cv2.COLOR_GRAY2BGR)

        # Find the maximum pixel intensity value (brightest point)
        max_intensity = np.max(self.gray_image)
        max_intensity_location = np.where(self.gray_image == max_intensity)

        # Get the coordinates of the brightest point
        x, y = max_intensity_location[1][0], max_intensity_location[0][0]

        # Draw an outer circle (red ring) around the brightest point
        inner_circle_radius = 10
        outer_circle_radius = inner_circle_radius + 3  # Slightly larger radius
        circle_color = (0, 0, 255)  # Red color
        cv2.circle(colour_image, (x, y), outer_circle_radius, circle_color, 2)  # Thickness = 1

        print(f"Circle drawn around the brightest point at ({x}, {y}).")
        #output_image_path = f"test {str(timer)} hotspot.jpg"
        cv2.imwrite("test.jpg", colour_image)
        print(f"Modified image saved as '{output_image_path}'")


def main(args=None):
    rclpy.init(args=args)

    print("1")

    minimal_subscriber = MinimalSubscriber()
    rclpy.spin(minimal_subscriber)

    print("2")

    #hotspot_detect.hotspot_detection(minimal_subscriber.cv_image, colour_image, gray_image)

    # Define Images
    #image_path = 'therm2.jpg'


   # print("3")

    # Call hotspot detection function
    #hotspot_detect.hotspot_detection(image_path, colour_image, gray_image)

    # Define name of image with hotspot located

    # Image saved message


    rclpy.shutdown()

if __name__ == '__main__':
    main()
