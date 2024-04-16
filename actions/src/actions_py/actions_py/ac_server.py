#!/usr/bin/env python3

import rclpy
import time
import numpy as np
import os
import random
from PIL import Image
from rclpy.node import Node
from rclpy.action import ActionServer
from rclpy.action.server import ServerGoalHandle
from hotspot_action.action import Acoustic

class ACServer(Node):
    def __init__(self):
        super().__init__("ac_server") 

        self.nav_server = ActionServer(self, 
            Acoustic, 
            "ac_server", 
            execute_callback=self.execute_callback)
        self.get_logger().info("Action Server has been started.")


    def execute_callback(self, goal_handle: ServerGoalHandle):
        take_ac_reading = goal_handle.request.take_ac_reading
        measurement_point = goal_handle.request.measurement_point
        pan_position = goal_handle.request.pan_position
        tilt_position = goal_handle.request.tilt_position
        self.get_logger().info(f"Received request to move to take ac reading")

        

        if take_ac_reading == True:
            self.ac_reading_sim(measurement_point, pan_position, tilt_position)

        
        goal_handle.succeed()
        result = Acoustic.Result()
        result.ac_save_path = self.output_reading_path
        print(f"Avergae dB value saved to {self.filename}")
        print(f"Grayscale image saved to {self.output_reading_path}")
        return result 
    
    def ac_reading_sim(self, measurement_point, pan_position, tilt_position):

        # Take AC reading
        time.sleep(5)

        # Create directory if it doesn't exist
        directory = os.path.join("photos", f"mp_{measurement_point}", "acoustic")
        if not os.path.exists(directory):
            os.makedirs(directory)

        # Define the filename to write the text into
        self.filename = os.path.join(directory, f"avg_db_values_{measurement_point}.txt")

        self.output_reading_path = os.path.join(directory, f"p_{pan_position}_t_{tilt_position}.jpg")

        image_size = (480, 640)
        scaling_factor = 255/40

        # Open the file in write mode
        with open(self.filename, 'a') as file:

            # Generate a random integer z from 0 to 40
            db_value = random.randint(0, 40)
    
            scaled_db_value = int(db_value * scaling_factor)

            # Write the formatted string to the file
            file.write(f"{db_value} dB\n")
            image_array = np.full(image_size, scaled_db_value, dtype=np.uint8)
            img = Image.fromarray(image_array, 'L')
            img.save(self.output_reading_path)
            


def main(args=None):
    rclpy.init(args=args)

    node = ACServer()

    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()