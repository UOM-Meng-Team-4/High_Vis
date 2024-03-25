#!/usr/bin/env python3

import rclpy
import cv2
import numpy as np
import pytesseract
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

            # Region of interests
            # High Temperature Reading
            self.HTy1 = 0
            self.HTy2 = 45
            self.HTx1 = 565
            self.HTx2 = 635
            self.HT_ROI =  self.cv_image[self.HTy1:self.HTy2, self.HTx1:self.HTx2]

            # Low Temperature Reading
            self.LTy1 = 435
            self.LTy2 = 475
            self.LTx1 = 565
            self.LTx2 = 635
            self.LT_ROI =  self.cv_image[self.LTy1:self.LTy2, self.LTx1:self.LTx2]

            # Limit area hotspot detection works in
            self.y1 = 55
            self.y2 = 425
            self.x1 = 0
            self.x2 = 540
            self.imROI = self.cv_image[self.y1:self.y2, self.x1:self.x2]

            # Text Recognition
            custom_config = r'--oem 3 --psm 6'
            HT_text = pytesseract.image_to_string(self.HT_ROI, config=custom_config)
            LT_text = pytesseract.image_to_string(self.LT_ROI, config=custom_config)
            print(f"Highest Temp = {HT_text}")
            print(f"Lowest Temp = {LT_text}")

            # Erosion and Dilation
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
        max_intensity = np.max(self.ed_image)
        max_intensity_location = np.where(self.ed_image == max_intensity)

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
        cv2.rectangle(self.cv_image, (self.HTx1, self.HTy1), (self.HTx2, self.HTy2), (0, 255, 0), 2)
        cv2.rectangle(self.cv_image, (self.LTx1, self.LTy1), (self.LTx2, self.LTy2), (255, 0, 255), 2)

        print(f"Circle drawn around the brightest point at ({x}, {y}).")
        self.measurement_point = 10
        output_image_path = f"{str(self.measurement_point)} hotspot.jpg"
        print(f"Modified image saved as '{output_image_path}'")
        cv2.imwrite(output_image_path, self.cv_image)
        #cv2.imwrite("eroded image.jpg", self.erosion_image)
        #cv2.imwrite("dilated image.jpg", self.dilated_image)
        #cv2.imwrite("ed image.jpg", self.ed_image)



def main(args=None):
    rclpy.init(args=args)

    minimal_subscriber = MinimalSubscriber()
    rclpy.spin_once(minimal_subscriber)

    rclpy.shutdown()

if __name__ == '__main__':
    main()

