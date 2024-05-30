#!/usr/bin/env python3

import rclpy
import time
import numpy as np
import os
from datetime import date
from std_msgs.msg import Int32
from PIL import Image
from rclpy.node import Node
from rclpy.action import ActionServer
from rclpy.action.server import ServerGoalHandle
from hotspot_action.action import Acoustic
from collections import deque

class ACServer(Node):
    def __init__(self):
        super().__init__("ac_server") 

        self.filepath = "~/HV_monitoring"
        self.filepath = os.path.expanduser(self.filepath)

        # Subscriber
        self.counter = 0
        self.previous_average = 0
        self.average = 0
        self.acoustic_subscriber = self.create_subscription(Int32, "cubemx_publisher", self.acoustic_callback, 10)

        # Action Server
        self.ac_server = ActionServer(self, 
            Acoustic, 
            "ac_server", 
            execute_callback=self.execute_callback)
        self.get_logger().info("Action Server has been started.")

        # Buffers
        self.pd_buffer = deque([0]*20,maxlen=20)
        self.get_pd_buffer = deque([0]*20,maxlen=20)

    # Subscriber Callback
    def acoustic_callback(self, msg: Int32):
        self.pd_buffer.appendleft(msg)

    # Action Server Callback
    def execute_callback(self, goal_handle: ServerGoalHandle):
        
        # Goal Handles
        take_ac_reading = goal_handle.request.take_ac_reading
        measurement_point = goal_handle.request.measurement_point
        pan_position = goal_handle.request.pan_position
        tilt_position = goal_handle.request.tilt_position
        self.today = goal_handle.request.today
        self.get_logger().info(f"Received request to move to take ac reading")

        if take_ac_reading == True:
            self.ac_reading_sim(measurement_point, pan_position, tilt_position)

        goal_handle.succeed()
        result = Acoustic.Result()
        result.ac_save_path = self.output_reading_path
        print(f"Average dB value saved to {self.filename}")
        print(f"Grayscale image saved to {self.output_reading_path}")
        return result 
    
    def ac_reading_sim(self, measurement_point, pan_position, tilt_position):

        # Take AC reading
        time.sleep(3)

        # Create directory if it doesn't exist
        #today = date.today().strftime("%d-%m-%Y")
        directory = os.path.join(self.filepath, "Scans", f"Substation_Scan_{self.today}", "2. Monitoring Images", f"mp_{measurement_point}", "acoustic")
        if not os.path.exists(directory):
            os.makedirs(directory)

        # Define the filename to write the text into
        self.filename = os.path.join(directory, f"avg_db_values.txt")

        # Define the path to save the image
        self.output_reading_path = os.path.join(directory, f"p_{pan_position}_t_{tilt_position}.jpg")

        # Define the image size and scaling factor
        image_size = (480, 640)
        scaling_factor = 255/40

        # Open the file in write node
        
        with open(self.filename, 'a') as file:
            
            # Get PD Data
            self.get_pd_buffer = self.pd_buffer

            for i in range(20):
        
                if self.get_pd_buffer[i].data > 1:
                    self.average = self.average + self.get_pd_buffer[i].data
                    self.counter = self.counter + 1

            if self.counter > 9:
                self.average = self.average / self.counter
                    
            else:
                self.average = 0

            print(f"counter = {self.counter}")
            print(f"average = {self.average}")

            scaled_average = self.average * scaling_factor

            self.counter = 0

            # Write the formatted string to the file
            file.write(f"{self.average:.1f} dB\n")
            image_array = np.full(image_size, scaled_average, dtype=np.uint8)
            img = Image.fromarray(image_array, 'L')
            img.save(self.output_reading_path)

        

def main(args=None):
    rclpy.init(args=args)

    node = ACServer()

    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
