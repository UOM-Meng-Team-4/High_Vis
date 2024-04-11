#!/usr/bin/env python3

import rclpy
import time
from rclpy.node import Node
from rclpy.action import ActionClient
from rclpy.action.client import ClientGoalHandle
from hotspot_action.action import Hotspot

class HotspotClient(Node):
    def __init__(self):
        super().__init__("hs_detection_client") # Change node name to what you want
        self.hs_detection_client = ActionClient(self, Hotspot, "hotspot_detection")

    def send_goal(self, take_image):
        # Wait for the server
        self.hs_detection_client.wait_for_server()

        # Create a goal
        goal = Hotspot.Goal()
        goal.take_image = take_image

        # Send the goal
        for i in range(5):
            self.get_logger().info(f"Sending goal {goal}")
            self.hs_detection_client. \
                send_goal_async(goal). \
                    add_done_callback(self.goal_response_callback)
            time.sleep(2)

    def goal_response_callback(self, future):
        self.goal_handle_: ClientGoalHandle = future.result()
        if self.goal_handle_.accepted: 
            self.goal_handle_.get_result_async().add_done_callback(self.goal_result_callback)

    def goal_result_callback(self, future):
        result = future.result().result
        self.get_logger().info(f"Result: " +str(result.hotspot_image_path))
        
        

def main(args=None):
    rclpy.init(args=args)

    node = HotspotClient()
    
    node.send_goal(True)

    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
