#!/usr/bin/env python3

import rclpy
import time
from rclpy.node import Node
from rclpy.action import ActionServer
from rclpy.action.server import ServerGoalHandle
from hotspot_action.action import Nav

class NavServer(Node):
    def __init__(self):
        super().__init__("nav_server") 

        self.nav_server = ActionServer(self, 
            Nav, 
            "nav_server", 
            execute_callback=self.execute_callback)
        self.get_logger().info("Action Server has been started.")

    def execute_callback(self, goal_handle: ServerGoalHandle):
        coordinate_x = goal_handle.request.coordinate_x
        coordinate_y = goal_handle.request.coordinate_y
        self.get_logger().info(f"Received request to move to ({coordinate_x}, {coordinate_y})")

        for t in range(6, 0, -1):
            time.sleep(1)
            goal_handle.publish_feedback(Nav.Feedback(time_to_mp = t))
            print(f"Reaching ({coordinate_x}, {coordinate_y}) in {t} s")

        goal_handle.succeed()
        result = Nav.Result()
        result.mp_reached = True
        print("Waypoint reached")
        return result
        
def main(args=None):
    rclpy.init(args=args)

    node = NavServer()

    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
