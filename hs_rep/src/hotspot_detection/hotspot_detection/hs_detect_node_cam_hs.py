#!/usr/bin/env python3

import rclpy
import cv2
import numpy as np
import pytesseract
import re
import requests
import json
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

    def get_ambient_temperature(self, city_name, api_key):
        base_url = "http://api.openweathermap.org/data/2.5/weather"
        params = {
            "q": city_name,
            "appid": api_key,
            "units": "metric"  # Use "imperial" for Fahrenheit
        }
        response = requests.get(base_url, params=params)
        data = response.json()
        return data["main"]["temp"]

    def image_callback(self, msg):

        # Ambient temperature
        self.city_name = "Manchester"
        self.api_key = "e7f19ea18faaa047a9505ccf73288a52"

        self.ambient_temp = self.get_ambient_temperature(self.city_name, self.api_key)
        #self.ambient_temp = 130

        print(f"Ambient temperature in {self.city_name} is {self.ambient_temp} degree Celsius")

        try:
            # Convert ROS 2 Image message to OpenCV format
            self.cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")

            # High Temperature Reading ROI
            self.HTy1 = 0
            self.HTy2 = 50
            self.HTx1 = 50
            self.HTx2 = 100 # May need to adjust this value if temp is approximate
            self.HT_ROI =  self.cv_image[self.HTy1:self.HTy2, self.HTx1:self.HTx2]

            # Preprocess the image
            self.HT_ROI = cv2.resize(self.HT_ROI, None, fx=2, fy=2, interpolation=cv2.INTER_CUBIC)
            gray = cv2.cvtColor(self.HT_ROI, cv2.COLOR_BGR2GRAY)
            _, self.HT_ROI = cv2.threshold(gray, 150, 255, cv2.THRESH_BINARY)
            cv2.imwrite("HT_ROI.jpg", self.HT_ROI)

             # Text Recognition
            custom_config = r'--oem 3 --psm 6'
            #self.HT_text = pytesseract.image_to_string(self.HT_ROI, config=custom_config)

            # Discard all non-numerical characters
            #self.HT_text = re.sub(r'\D', '', self.HT_text)
            self.HT_text = 60
            print(f"Hotspot Temp = {self.HT_text}")

            # Limit area hotspot detection works in
            self.y1 = 70
            self.y2 = 410
            self.x1 = 30
            self.x2 = 602
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

        # Convert the image to grayscale
        gray = cv2.cvtColor(self.imROI, cv2.COLOR_BGR2GRAY)
        # cv2.imwrite("gray.jpg", gray)

        # K-means clustering
        pixel_vals = gray.reshape((-1, 2))     
        pixel_vals = np.float32(pixel_vals)  
        criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 100, 0.85) 
        k = 5
        retval, labels, centers = cv2.kmeans(pixel_vals, k, None, criteria, 10, cv2.KMEANS_RANDOM_CENTERS) 

        # Calculate the mean grayscale value for each cluster
        mean_values = np.zeros(k)
        for i in range(k):
            mean_values[i] = np.mean(pixel_vals[labels.flatten() == i])
        
        # Find the cluster with the highest mean value (hotspot)
        max_center = np.argmax(mean_values)   
        mask = labels.flatten() == (max_center)
         
        segmented_data = np.zeros_like(pixel_vals, dtype=np.uint8)    
        segmented_data[mask] = 255
        
        # Reshape the segmented data into the original image shape with mask
        thresholded = segmented_data.reshape((gray.shape))
      
        # Dilation
        #_, thresholded = cv2.threshold(thresholded, 150, 255, cv2.THRESH_BINARY)
        #thresholded = cv2.erode(thresholded, kernel, iterations=3)
        kernel = np.ones((3,3), np.uint8)
        thresholded = cv2.dilate(thresholded, kernel, iterations=10)
        cv2.imwrite("hotspot photos/thresholded.jpg", thresholded)

        # Find contours in the thresholded image
        contours, _ = cv2.findContours(thresholded, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

        # Correct for offset due to imROI
       
        for contour in contours:

            contour[:, :, 1] += 70
            contour[:, :, 0] += 30

            # Calculate the rotated bounding rectangle of the contour
            rect = cv2.minAreaRect(contour)
            box = cv2.boxPoints(rect)
            box = np.int0(box)

            # Draw the rectangle
            # Using ANSI/NETA standard for temperature classification
            hs_temp = int(float(self.HT_text)) - self.ambient_temp
            if 1<hs_temp<10: 
                cv2.drawContours(self.cv_image, [box], 0, (0, 255, 0), 2)       # Green

            elif 11<hs_temp<20:
                cv2.drawContours(self.cv_image, [box], 0, (0, 255, 128), 2)     # Yellow
                
            elif 21<hs_temp<40:
                cv2.drawContours(self.cv_image, [box], 0, (0, 165, 255), 2)     # Orange

            elif hs_temp>40:
                cv2.drawContours(self.cv_image, [box], 0, (0, 0, 255), 2)   # Red

            else:
                pass
            
            print(f"Rectangle drawn around the hotspot at ({x}, {y}).")

        
        # Draw contours for testing
        #cv2.drawContours(self.cv_image, contours, -1, (0,255,0), 3)

        # Draw rectangle for ROI (Optional)
        #cv2.rectangle(self.cv_image, (self.x1, self.y1), (self.x2, self.y2), (255, 0, 0), 2)
        #cv2.rectangle(self.cv_image, (self.HTx1, self.HTy1), (self.HTx2, self.HTy2), (0, 255, 0), 2)
        
        # Measurement point (needs to be adaptive in future)
        self.measurement_point = 3

        # Save image with hotspot located
        output_image_path = f"hotspot photos/sub_hs_{str(self.measurement_point)} hotspot.jpg"
        print(f"Modified image saved as '{output_image_path}'")
        cv2.imwrite(output_image_path, self.cv_image)
        
def main(args=None):
    rclpy.init(args=args)

    minimal_subscriber = MinimalSubscriber()
    rclpy.spin_once(minimal_subscriber)

    rclpy.shutdown()

if __name__ == '__main__':
    main()

