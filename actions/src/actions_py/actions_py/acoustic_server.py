#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from collections import deque

#-------------------------ACOUSTIC-NODE-CREATES-SUBSCRIPTION------------------
class AcousticNode(Node):
    def __init__(self):
        super().__init__("acoustic_subscriber")
        self.counter = 0
        self.previous_average = 0
        self.average = 0
        self.acoustic_subscriber = self.create_subscription(type, "cubemx_publisher", self.acoustic_callback, 10)

        self.pd_buffer = deque([0]*20,maxlen=20)
        self.get_pd_buffer = deque([0]*20,maxlen=20)

#-------------------------SUBSCRIBER-CALLBACK-------------------------------- 
    def acoustic_callback(self, msg: type):
        self.pd_buffer.appendleft(msg)

#----------------------SAVING-DATA-------------------------------------------
#To be called at each observation point
    def acoustic_get_data(self, msg: type)
        self.get_pd_buffer = self.pd_buffer
        for i in range(20):
            if self.get_pd_buffer(i) > 1
                self.average = self.average + self.get_pd_buffer(i)
                self.counter = self.counter + 1
            elif self.counter > 9:
                self.average = self.average / self.counter
            else:
                self.average = 0

            self.counter = 0

            file1 = open("acoustic_data.txt", "a")
            file1.write(str(self.average)+"\n")
            file1.close()

def main(args=None):

    rclpy.init(args=args)
    node = AcousticNode()
    rclpy.spin(node)
    rclpy.shutdown()
