#!/usr/bin/env python3

import rclpy
import time
import numpy as np
from std_msgs.msg import Int32
from rclpy.node import Node
from rclpy.action import ActionServer
from rclpy.action.server import ServerGoalHandle
from hotspot_action.action import PanAndTilt
from rclpy.callback_groups import MutuallyExclusiveCallbackGroup
from rclpy.executors import MultiThreadedExecutor

class PTServer(Node):
    def __init__(self):
        super().__init__("pt_server") 

        self.pan = 10
        self.tilt = 10
        self.p = 0
        self.t = 0

        pubsub_group = None
        server_group = None

        self.pt_server = ActionServer(self, 
            PanAndTilt, 
            "pt_server", 
            execute_callback=self.execute_callback,
            callback_group=server_group)
        self.get_logger().info("Action Server has been started.")

        self.publisher = self.create_publisher(Int32, "pt_subscriber", 10, callback_group=pubsub_group)
        self.timer = self.create_timer(0.04, self.timer_callback)
        self.subscriber = self.create_subscription(Int32, "pt_publisher", self.subscriber_callback, 10, callback_group=pubsub_group)

    def execute_callback(self, goal_handle: ServerGoalHandle):
        self.pan = goal_handle.request.pan
        self.tilt = goal_handle.request.tilt
        self.get_logger().info(f"Received request to move to pan position:{self.pan}, tilt position:{self.tilt}")
        print(f"{self.p} = {self.pan}")
        print(f"{self.t} = {self.tilt}")

        while not((self.pan-5)<=self.p<=(self.pan+5) and (self.tilt-5)<=self.t<=(self.tilt+5)):
            goal_handle.publish_feedback(PanAndTilt.Feedback(pan_feedback = self.p, tilt_feedback = self.t))
            

        goal_handle.succeed()
        result = PanAndTilt.Result()
        result.move_finished = True
        print("Pan Position reached")
        return result
                

    def timer_callback(self):
        #print(f"{self.pan}, {self.tilt}")
        msg = Int32()
        msg.data = self.pan|(self.tilt<<9) 
        self.publisher.publish(msg)
        #self.get_logger().info(f"Publishing: {msg.data}")

    def subscriber_callback(self, msg: Int32):
        self.p = msg.data&511
        self.t = msg.data>>9
        #print(f"{self.p}, {self.t}")

        
        
def main(args=None):
    rclpy.init(args=args)
    node = PTServer()
    executor = MultiThreadedExecutor()
    executor.add_node(node)

    executor.spin()
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
