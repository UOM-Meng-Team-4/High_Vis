#!/usr/bin/env python3

import rclpy
import cv2
import numpy as np
import pytesseract
import re
from pytesseract import Output
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

            # High Temperature Reading ROI
            self.HTy1 = 0
            self.HTy2 = 50
            self.HTx1 = 50
            self.HTx2 = 125 # May need to adjust this value if temp is approximate
            self.HT_ROI =  self.cv_image[self.HTy1:self.HTy2, self.HTx1:self.HTx2]

            # Preprocess the image
            self.HT_ROI = cv2.resize(self.HT_ROI, None, fx=2, fy=2, interpolation=cv2.INTER_CUBIC)
            gray = cv2.cvtColor(self.HT_ROI, cv2.COLOR_BGR2GRAY)
            _, self.HT_ROI = cv2.threshold(gray, 150, 255, cv2.THRESH_BINARY)
            cv2.imwrite("HT_ROI.jpg", self.HT_ROI)

             # Text Recognition
            custom_config = r'--oem 3 --psm 6'
            self.HT_text = pytesseract.image_to_string(self.HT_ROI, config=custom_config)

            # Discard all non-numerical characters
            self.HT_text = re.sub(r'\D', '', self.HT_text)
            print(f"Hotspot Temp = {self.HT_text}")

            # Limit area hotspot detection works in
            self.y1 = 70
            self.y2 = 410
            self.x1 = 20
            self.x2 = 500
            self.imROI = self.cv_image[self.y1:self.y2, self.x1:self.x2]

            # Call hotspot detection function
            MinimalSubscriber.hotspot_detection(self)

        # Error handling
        except Exception as e:
            self.get_logger().error(f"Error processing image: {str(e)}")

    def hotspot_detection(self):

        # Find the maximum pixel intensity value (brightest point)
        max_intensity = np.max(self.imROI)
        max_intensity_location = np.where(self.imROI == max_intensity)

        # Get the coordinates of the brightest point
        x, y = max_intensity_location[1][0], max_intensity_location[0][0]

        # Only draw a rectangle when hotspot is over 100 degC

        if int(float(self.HT_text)) > 100:

            # Convert the image to grayscale
            gray = cv2.cvtColor(self.imROI, cv2.COLOR_BGR2GRAY)
            # cv2.imwrite("gray.jpg", gray)

            # Thresholding and Dilation
            _, thresholded = cv2.threshold(gray, 110, 255, cv2.THRESH_BINARY)
            kernel = np.ones((3,3), np.uint8)
            thresholded = cv2.dilate(thresholded, kernel, iterations=5)
            # cv2.imwrite("thresholded.jpg", thresholded)

            # Find contours in the thresholded image
            contours, _ = cv2.findContours(thresholded, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

            # Correct for offset due to imROI
            for contour in contours:
                contour[:,0,1] += 85

            # Find the largest contour (assuming this is the hotspot)
            largest_contour = max(contours, key=cv2.contourArea)

            # Calculate the rotated bounding rectangle of the largest contour
            rect = cv2.minAreaRect(largest_contour)
            box = cv2.boxPoints(rect)
            box = np.int0(box)

            # Draw contours for testing
            cv2.drawContours(self.cv_image, contours, -1, (0,255,0), 3)

            # Draw the rectangle
            cv2.drawContours(self.cv_image, [box], 0, (0, 0, 255), 2)
            
            print(f"Rectangle drawn around the hotspot at ({x}, {y}).")

        # Draw rectangle for ROI (Optional)
        cv2.rectangle(self.cv_image, (self.x1, self.y1), (self.x2, self.y2), (255, 0, 0), 2)
        cv2.rectangle(self.cv_image, (self.HTx1, self.HTy1), (self.HTx2, self.HTy2), (0, 255, 0), 2)
        
        # Measurement point (needs to be adaptive in future)
        self.measurement_point = 12

        # Save image with hotspot located
        output_image_path = f"{str(self.measurement_point)} hotspot.jpg"
        print(f"Modified image saved as '{output_image_path}'")
        cv2.imwrite(output_image_path, self.cv_image)
        
def main(args=None):
    rclpy.init(args=args)

    minimal_subscriber = MinimalSubscriber()
    rclpy.spin_once(minimal_subscriber)

    rclpy.shutdown()

if __name__ == '__main__':
    main()

