#!/usr/bin/env python3

import rclpy
import time
import threading
from rclpy.node import Node
from rclpy.action import ActionClient
from rclpy.action.client import ClientGoalHandle
from hotspot_action.action import Hotspot
from hotspot_action.action import Nav
from hotspot_action.action import PanAndTilt

def spin_node(node):
    rclpy.spin(node)

class HS_Client(Node):
    def __init__(self):
        super().__init__("hs_client") # Change node name to what you want
        self.hs_client = ActionClient(self, Hotspot, "hotspot_detection")
        self.hs_result = None

    def send_hs_goal(self, take_image, measurement_point, pan_position, tilt_position):
        # Wait for the server
        self.hs_client.wait_for_server()

        # Create a goal
        goal = Hotspot.Goal()
        goal.take_image = take_image
        goal.measurement_point = measurement_point
        goal.pan_position = pan_position
        goal.tilt_position = tilt_position

        # Send the goal       
        self.get_logger().info(f"Sending hs goal")
        self.hs_client. \
            send_goal_async(goal). \
                add_done_callback(self.goal_response_callback)
        
    def goal_response_callback(self, future):
        self.goal_handle_: ClientGoalHandle = future.result()
        if self.goal_handle_.accepted: 
            self.goal_handle_.get_result_async().add_done_callback(self.goal_result_callback)

    def goal_result_callback(self, future):
        result = future.result().result
        self.hs_result = result.hotspot_image_path
        self.get_logger().info(f"Result: " +str(result.hotspot_image_path))
        

class Nav_Client(Node):

    def __init__(self):
        super().__init__("nav_client") # Change node name to what you want
        self.nav_client = ActionClient(self, Nav, "nav_server")
        self.nav_result = None
        

    def send_nav_goal(self, coordinate_x, coordinate_y):
        # Wait for the server
        if not self.nav_client.wait_for_server(timeout_sec=5.0):
            self.get_logger().info('Nav server not available after waiting')
            return

        # Create a goal
        goal = Nav.Goal()
        goal.coordinate_x = coordinate_x
        goal.coordinate_y = coordinate_y
        

        # Send the goal       
        self.get_logger().info(f"Sending nav goal")
        self.nav_client. \
            send_goal_async(goal, feedback_callback=self.feedback_callback). \
                add_done_callback(self.goal_response_callback)
       
        
    def goal_response_callback(self, future):
        self.goal_handle_: ClientGoalHandle = future.result()
        if self.goal_handle_.accepted: 
            self.goal_handle_.get_result_async().add_done_callback(self.goal_result_callback)

    def goal_result_callback(self, future):
        result = future.result().result
        self.get_logger().info(f"Result: " +str(result.mp_reached))

        if result is not None:
            self.nav_result = result.mp_reached

    def feedback_callback(self, feedback_msg):
        feedback = feedback_msg.feedback
        self.get_logger().info(f"Time to next measurement point: {feedback.time_to_mp}")

         
class PT_Client(Node):

    def __init__(self):
        super().__init__("pt_client") # Change node name to what you want
        self.pt_client = ActionClient(self, PanAndTilt, "pt_server")

    def send_pt_goal(self, pan, tilt):
        # Wait for the server
        self.pt_client.wait_for_server()

        # Create a goal
        goal = PanAndTilt.Goal()
        goal.pan = pan
        goal.tilt = tilt

        # Send the goal       
        self.get_logger().info(f"Sending pan and tilt goal")
        self.pt_client. \
            send_goal_async(goal). \
                add_done_callback(self.goal_response_callback)
        
    def goal_response_callback(self, future):
        self.goal_handle_: ClientGoalHandle = future.result()
        if self.goal_handle_.accepted: 
            self.goal_handle_.get_result_async().add_done_callback(PT_Client.goal_result_callback)

    def goal_result_callback(self, future):
        result = future.result().result
        self.get_logger().info(f"Result: " +str(result.move_finished))

        if result is not None:
            self.pt_result = result.move_finished

    def feedback_callback(self, feedback):
        self.get_logger().info(f"Pan Angle: {feedback.pan_feedback}, Tilt Angle: {feedback.tilt_feedback}")




def main(args=None):
    rclpy.init(args=args)

    # Measurement Points
    measurement_points = [
    [26.80, -3.74],
    [26.20, -13.74],
    [26.4, -19.6],
    [25.1,-25.1],
    [12.4, -17.9],
    [9.29, -16.9],
    [0.0 , 0.0]]

    pan_positions = [1, 2, 3]
    tilt_positions = [1, 2, 3]

    hotspot_node = HS_Client()
    nav_node = Nav_Client()
    pt_node = PT_Client()

    # Tell nav server to move to next waypoint
    nav_node.send_nav_goal(measurement_points[0][0], measurement_points[0][1])

    while nav_node.nav_result is None:
        rclpy.spin_once(nav_node)

    # Tell PT server to move to next pan/tilt position
    if nav_node.nav_result:
        pt_node.send_pt_goal(pan_positions[1], tilt_positions[1])
        while pt_node.pt_result is None:
            rclpy.spin_once(pt_node)

    # Tell Hotpot server to take a thermal image
    if pt_node.pt_result:
        hotspot_node.send_hs_goal(True, 1, 1, 1)
        while hotspot_node.hs_result is None:
            rclpy.spin_once(hotspot_node)

    


    #rclpy.spin(hotspot_node)
    #rclpy.spin(nav_node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
