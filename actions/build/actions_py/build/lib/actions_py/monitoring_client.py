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
from hotspot_action.action import Acoustic

class Client(Node):
    def __init__(self):
        super().__init__("client") # Change node name to what you want
        self.hs_client = ActionClient(self, Hotspot, "hotspot_server")
        self.nav_client = ActionClient(self, Nav, "nav_server")
        self.pt_client = ActionClient(self, PanAndTilt, "pt_server")
        self.ac_client = ActionClient(self, Acoustic, "ac_server")
        self.pt_result = None
        self.nav_result = None
        self.hs_result = None
        self.ac_result = None

    # Hotspot

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
                add_done_callback(self.goal_response_callback_hs)
        
    def goal_response_callback_hs(self, future):
        self.goal_handle_: ClientGoalHandle = future.result()
        if self.goal_handle_.accepted: 
            self.goal_handle_.get_result_async().add_done_callback(self.goal_result_callback_hs)

    def goal_result_callback_hs(self, future):
        result = future.result().result
        self.hs_result = result.hotspot_image_path
        self.get_logger().info(f"Result: " +str(result.hotspot_image_path))

    # Navigation

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
            send_goal_async(goal, feedback_callback=self.feedback_callback_nav). \
                add_done_callback(self.goal_response_callback_nav)
        
        
    def goal_response_callback_nav(self, future):
        self.goal_handle_: ClientGoalHandle = future.result()
        if self.goal_handle_.accepted: 
            self.goal_handle_.get_result_async().add_done_callback(self.goal_result_callback_nav)

    def goal_result_callback_nav(self, future):
        result = future.result().result
        self.get_logger().info(f"Result: " +str(result.mp_reached))
        self.nav_result = result.mp_reached

    def feedback_callback_nav(self, feedback_msg):
        feedback = feedback_msg.feedback
        self.get_logger().info(f"Time to next measurement point: {feedback.time_to_mp}")


    # Pan and Tilt

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
            send_goal_async(goal, feedback_callback=self.feedback_callback_pt). \
                add_done_callback(self.goal_response_callback_pt)
        
        
    def goal_response_callback_pt(self, future):
        self.goal_handle_: ClientGoalHandle = future.result()
        if self.goal_handle_.accepted: 
            self.goal_handle_.get_result_async().add_done_callback(self.goal_result_callback_pt)

    def goal_result_callback_pt(self, future):
        result = future.result().result
        self.get_logger().info(f"Result: " +str(result.move_finished))
        self.pt_result = result.move_finished

    def feedback_callback_pt(self, feedback_msg):
        feedback = feedback_msg.feedback
        self.get_logger().info(f"Pan Angle: {feedback.pan_feedback:.1f}, Tilt Angle: {feedback.tilt_feedback:.1f}")

    
    # Acoustic

    def send_ac_goal(self, take_ac_reading, measurement_point, pan_position, tilt_position):
        # Wait for the server
        self.ac_client.wait_for_server()

        # Create a goal
        goal = Acoustic.Goal()
        goal.take_ac_reading = take_ac_reading
        goal.measurement_point = measurement_point
        goal.pan_position = pan_position
        goal.tilt_position = tilt_position

        # Send the goal       
        self.get_logger().info(f"Sending ac goal")
        self.ac_client. \
            send_goal_async(goal). \
                add_done_callback(self.goal_response_callback_ac)
        
    def goal_response_callback_ac(self, future):
        self.goal_handle_: ClientGoalHandle = future.result()
        if self.goal_handle_.accepted: 
            self.goal_handle_.get_result_async().add_done_callback(self.goal_result_callback_ac)

    def goal_result_callback_ac(self, future):
        result = future.result().result
        self.ac_result = result.ac_save_path
        self.get_logger().info(f"Result: " +str(result.ac_save_path))

