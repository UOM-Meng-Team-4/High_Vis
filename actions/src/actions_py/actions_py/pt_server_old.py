#!/usr/bin/env python3

import rclpy
import time
import numpy as np
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

        self.p = self.previous_tilt = 0
        self.t = self.previous_pan = 0

    def execute_callback(self, goal_handle: ServerGoalHandle):
        pan = goal_handle.request.pan
        tilt = goal_handle.request.tilt
        self.get_logger().info(f"Received request to move to pan position:{pan}, tilt position:{tilt}")


        if self.previous_tilt < tilt:
            for self.t in np.arange(self.previous_tilt, tilt, 1):
                #time.sleep(0.1)
                goal_handle.publish_feedback(PanAndTilt.Feedback(pan_feedback = int(self.p), tilt_feedback = int(self.t)))
                print(f"Reaching tilt position {self.t:.1f}")  

        if self.previous_pan < pan:
            for self.p in np.arange(self.previous_pan, pan, 1):
                #time.sleep(0.1)
                goal_handle.publish_feedback(PanAndTilt.Feedback(pan_feedback = int(self.p), tilt_feedback = int(self.t)))
                print(f"Reaching pan position {self.p:.1f}")
        
        else:
            print("No movement required")

        self.previous_tilt = tilt
        self.previous_pan = pan

        goal_handle.succeed()
        result = PanAndTilt.Result()
        result.move_finished = True
        print("Pan Position reached")
        return result
            
        
def main(args=None):
    rclpy.init(args=args)

    node = PTServer()

    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()