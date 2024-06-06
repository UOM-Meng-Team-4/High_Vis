#!/usr/bin/env python3

import rclpy
import time
import os
from datetime import datetime
from rclpy.node import Node
from rclpy.action import ActionClient
from rclpy.action.client import ClientGoalHandle
from hotspot_action.action import Hotspot
from hotspot_action.action import Nav
from hotspot_action.action import PanAndTilt
from hotspot_action.action import Acoustic
from hotspot_action.action import Visual

class Client(Node):
    def __init__(self):
        super().__init__("client") # Change node name to what you want
        self.hs_client = ActionClient(self, Hotspot, "hotspot_server")
        self.nav_client = ActionClient(self, Nav, "nav_server")
        self.pt_client = ActionClient(self, PanAndTilt, "pt_server")
        #self.ac_client = ActionClient(self, Acoustic, "ac_server")
        self.visual_client = ActionClient(self, Visual, "visual_cam_server")
        self.pt_result = None
        self.nav_result = None
        self.hs_result = None
        #self.ac_result = None
        self.visual_result = None
        self.today  = datetime.today().strftime('%d-%m-%Y_%H-%M-%S')

        

    # Hotspot

    def send_hs_goal(self, take_image, measurement_point, pan_position, tilt_position):
        # Wait for the server
        if not self.hs_client.wait_for_server(timeout_sec=1.0):
            self.get_logger().info('Hotspot server not available after waiting')
            return

        # Create a goal
        goal = Hotspot.Goal()
        goal.take_image = take_image
        goal.measurement_point = measurement_point
        goal.pan_position = pan_position
        goal.tilt_position = tilt_position
        goal.today = self.today

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

    # Visual Cam

    def send_visual_goal(self, take_visual_image, measurement_point, pan_position, tilt_position):
        # Wait for the server
        if not self.visual_client.wait_for_server(timeout_sec=1.0):
            self.get_logger().info('Visual Cam server not available after waiting')
            return

        # Create a goal
        goal = Visual.Goal()
        goal.take_visual_image = take_visual_image
        goal.measurement_point = measurement_point
        goal.pan_position = pan_position
        goal.tilt_position = tilt_position
        goal.today = self.today

        # Send the goal       
        self.get_logger().info(f"Sending visual cam goal")
        self.visual_client. \
            send_goal_async(goal). \
                add_done_callback(self.goal_response_callback_visual)
        
    def goal_response_callback_visual(self, future):
        self.goal_handle_: ClientGoalHandle = future.result()
        if self.goal_handle_.accepted: 
            self.goal_handle_.get_result_async().add_done_callback(self.goal_result_callback_visual)

    def goal_result_callback_visual(self, future):
        result = future.result().result
        self.visual_result = result.visual_image_path
        self.get_logger().info(f"Result: " +str(result.visual_image_path))

    # Navigation

    def send_nav_goal(self, coordinate_x, coordinate_y):
        # Wait for the server
        if not self.nav_client.wait_for_server(timeout_sec=1.0):
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
        if not self.pt_client.wait_for_server(timeout_sec=1.0):
            self.get_logger().info('PT server not available after waiting')
            return

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

    '''
    
    # Acoustic

    def send_ac_goal(self, take_ac_reading, measurement_point, pan_position, tilt_position):
        # Wait for the server
        if not self.ac_client.wait_for_server(timeout_sec=1.0):
            self.get_logger().info('Acoustic server not available after waiting')
            return

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

    '''



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

    mp_int = 0
    p_int = 0
    t_int = 0
    pan_positions = [10, 36, 72, 108, 144, 180, 216, 252, 288, 324, 360]
    tilt_positions = [10, 20, 40, 60]


    node = Client()

    for mp in measurement_points:

        mp_int += 1

        # Send nav goal
        node.nav_result = node.send_nav_goal(mp[0], mp[1])



        while node.nav_result is None:
            rclpy.spin_once(node)
           

        node.nav_result = None
            
        for p in pan_positions:
            p_int += 1
            for t in tilt_positions:
            
                # Send pt goal
                #time.sleep(2)
                node.pt_result = node.send_pt_goal(p, t)

                
                t_int += 1

                while node.pt_result is None:
                    rclpy.spin_once(node)

                node.pt_result = None

                # Send hs goal
                node.hs_result= node.send_hs_goal(True, mp_int, p_int, t_int)
                node.visual_result = node.send_visual_goal(True, mp_int, p_int, t_int)
                #node.ac_result = node.send_ac_goal(True, mp_int, p_int, t_int)
                                                                          
            
                while node.hs_result is None:
                    while node.visual_result is None:
                   #     while node.ac_result is None:
                        rclpy.spin_once(node, timeout_sec=5.0)
                        
                        #print(node.visual_result)

                    rclpy.spin_once(node, timeout_sec=5.0)
                    #print(node.hs_result)
                    
                node.hs_result = None
                node.visual_result = None

                node.pt_result = node.send_pt_goal(10, 10)
                #node.ac_result = None

                #time.sleep(2)

            t_int = 0

        p_int = 0
        


    #rclpy.spin(node)

    rclpy.shutdown()

if __name__ == '__main__':
    main()
