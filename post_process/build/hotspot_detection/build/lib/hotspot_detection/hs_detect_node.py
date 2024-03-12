#!/usr/bin/env python3

import rclpy
import cv2
import numpy as np
from rclpy.node import Node

class MyNode(Node):
    def __init__(self):
        super().__init__("hotspot_detect") # Change node name to what you want

    def hotspot_detection(image_path, colour_image, gray_image):

        # Find the maximum pixel intensity value (brightest point)
        max_intensity = np.max(gray_image)
        max_intensity_location = np.where(gray_image == max_intensity)

        # Get the coordinates of the brightest point
        x, y = max_intensity_location[1][0], max_intensity_location[0][0]

        # Draw an outer circle (red ring) around the brightest point
        inner_circle_radius = 10
        outer_circle_radius = inner_circle_radius + 3  # Slightly larger radius
        circle_color = (0, 0, 255)  # Red color
        cv2.circle(colour_image, (x, y), outer_circle_radius, circle_color, 2)  # Thickness = 1

        print(f"Circle drawn around the brightest point at ({x}, {y}).")

def main(args=None):
    rclpy.init(args=args)

    # Define Images
    image_path = 'therm2.jpg'
    gray_image = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)
    colour_image = cv2.cvtColor(gray_image, cv2.COLOR_GRAY2BGR)

    # Call hotspot detection function
    MyNode.hotspot_detection(image_path, colour_image, gray_image)

    # Define name of image with hotspot located
    output_image_path = f'{image_path}_hotspot.jpg'
    cv2.imwrite(output_image_path, colour_image)

    # Image saved message
    print(f"Modified image saved as '{output_image_path}'")

    # rclpy.spin(MyNode) if you want to spin the node
    rclpy.shutdown()

if __name__ == '__main__':
    main()
