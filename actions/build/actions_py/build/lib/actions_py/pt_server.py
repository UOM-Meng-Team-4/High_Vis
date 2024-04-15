#!/usr/bin/env python3

import rclpy
import time
from rclpy.node import Node
from rclpy.action import ActionServer
from rclpy.action.server import ServerGoalHandle
from hotspot_action.action import PanAndTilt

class PTServer(Node):
    def __init__(self):
        super().__init__("pt_server") 

        self.nav_server = ActionServer(self, 
            PanAndTilt, 
            "pt_server", 
            execute_callback=self.execute_callback)
        self.get_logger().info("Action Server has been started.")

    def execute_callback(self, goal_handle: ServerGoalHandle):
        pan = goal_handle.request.pan
        tilt = goal_handle.request.tilt
        self.get_logger().info(f"Received request to move to pan position:{pan}, tilt position:{tilt}")

        previous_tilt = 0
        previous_pan = 0

        if previous_tilt > tilt:
            for t in range(previous_tilt, tilt, -0.5):
                time.sleep(0.5)
                goal_handle.publish_feedback(PanAndTilt.Feedback(tilt_feedback = t))
                print(f"Reaching tilt position {t}")

            goal_handle.succeed()
            result = PanAndTilt.Result()
            result.move_finished = True
            print("Tilt Position reached")
            return result

        if previous_pan > pan:
            for p in range(previous_pan, pan, -0.5):
                time.sleep(0.5)
                goal_handle.publish_feedback(PanAndTilt.Feedback(pan_feedback = p))
                print(f"Reaching pan position {p}")

            goal_handle.succeed()
            result = PanAndTilt.Result()
            result.move_finished = True
            print("Pan Position reached")
            return result
        
        else:
            print("No movement required")

        previous_tilt = tilt
        previous_pan = pan
            
        
def main(args=None):
    rclpy.init(args=args)

    node = PTServer()

    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
