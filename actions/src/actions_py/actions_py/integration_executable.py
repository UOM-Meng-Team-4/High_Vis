#! /usr/bin/env python3

from datetime import datetime
from actions_py.monitoring_client import Client
from geometry_msgs.msg import PoseStamped
from nav2_simple_commander.robot_navigator import BasicNavigator, TaskResult
import rclpy
import copy
from rclpy.duration import Duration
from rclpy.node import Node
import yaml
import os

class IntegrationExecutable(Node):

    def __init__(self):
        super().__init__("integration_executable")
        self.mp_int = 0
        self.today = datetime.today().strftime('%d-%m-%Y_%H-%M-%S')

    def run_navigator(self, navigator, inspection_route, client):
        yaml_file = "~/HV_monitoring/route.yaml"
        yaml_file = os.path.expanduser(yaml_file)
        # open the yaml file and load the points
        with open(yaml_file, "r") as f:
            points = yaml.safe_load(f)
 
        # Extract the x, y, and z values from the points
        points_list = [[point["x"], point["y"], point["z"], point["Complete"]] for point in points.values() if isinstance(point, dict) and "x" in point and "y" in point and "z" in point and "Complete" in point]
        
        #Loads in the map from the points.yaml file
        map = points["map"]
        map = os.path.expanduser(map)
        try:
            navigator.changeMap(map)
        except Exception as e:
            print(f"Error loading map: {e}")
        
        # Extract the initial x, y, and z values
        initial_x = points["initial_point"]["initial_x"]
        initial_y = points["initial_point"]["initial_y"]
        initial_z = points["initial_point"]["initial_z"]

        # Set the initial pose of the robot
        initial_pose = PoseStamped()
        initial_pose.header.frame_id = 'map'
        initial_pose.header.stamp = navigator.get_clock().now().to_msg()
        initial_pose.pose.position.x = initial_x
        initial_pose.pose.position.y = initial_y
        initial_pose.pose.orientation.z = initial_z
        initial_pose.pose.orientation.w = 1.0

        navigator.waitUntilNav2Active()

        # Load In Correct Map below. 
        # navigator.changeMap('/path/to/map.yaml')

        while rclpy.ok():
            
            #Sets the list of poses for the inspection route
            inspection_points = []
            inspection_pose = PoseStamped()
            inspection_pose.header.frame_id = 'map'
            inspection_pose.header.stamp = navigator.get_clock().now().to_msg()
            #inspection_pose.pose.orientation.z = 0.0
            inspection_pose.pose.orientation.w = 1.0
            for pt in points_list:
                inspection_pose.pose.position.x = pt[0]
                inspection_pose.pose.position.y = pt[1]
                inspection_pose.pose.orientation.z = pt[2]
                inspection_points.append(copy.deepcopy(inspection_pose))
                
            
            for point in inspection_points:
                navigator.goToPose(point)
                i = 0
                feedback = navigator.getFeedback()
                while not navigator.isTaskComplete():
                
                    i = i +1
                    feedback = navigator.getFeedback()
                    

                    if feedback and i % 5==0 :
                        navigator.info('Estimated time of arrival: ' + '{0:.0f}'.format(
                        Duration.from_msg(feedback.estimated_time_remaining).nanoseconds / 1e9)
                        + ' seconds.')

                        # Some navigation timeout to demo cancellation
                        if Duration.from_msg(feedback.navigation_time) > Duration(seconds=600.0):
                            #If the robot is taking too long to reach the goal, cancel the task
                            navigator.cancelTask()
                            break
                        # Some navigation request change to demo preemption
                        if Duration.from_msg(feedback.navigation_time) > Duration(seconds=150.0):
                            # Resends the goal position if the robot is taking too long to reach the goal
                            navigator.cancelTask()
                            navigator.spin()
                            navigator.goToPose(point)
                            
                #Get Current Pose of robot
                self.current_pose = feedback.current_pose

                self.result = navigator.getResult()
                if self.result == TaskResult.SUCCEEDED:
            
                    navigator.info('Goal succeeded!')
                    current_pose  = self.current_pose
                    navigator.info(f'Current pose {current_pose.pose.position.x}')
                    pt[3] = 1
                    pt[2] = self.current_pose.pose.orientation.z
                    # Run Pan and Tilt
                    
                    self.run_pan_tilt(client)

                elif self.result == TaskResult.CANCELED:
                    #Run Code to move to next Goal 
                    
                    navigator.info('Goal was canceled!')
                    #continue
                    pt[3] = 0
                    pt[2] = self.current_pose.pose.orientation.z
                
                elif self.result == TaskResult.FAILED:
                    navigator.info('Goal failed!')
                    pt[3] = 0
                    pt[2] = self.current_pose.pose.orientation.z
                    #continue

                else:
                    print('Goal has an invalid return status!')
                    pt[3] = 0
            navigator.goToPose(initial_pose)
            while not navigator.isTaskComplete():
                feedback = navigator.getFeedback()
                if feedback:
                    navigator.info('Estimated time of arrival: ' + '{0:.0f}'.format(
                        Duration.from_msg(feedback.estimated_time_remaining).nanoseconds / 1e9)
                        + ' seconds.')
                    if Duration.from_msg(feedback.navigation_time) > Duration(seconds=600.0):
                        navigator.goToPose(initial_pose)
                        break
                    if Duration.from_msg(feedback.navigation_time) > Duration(seconds=1000.0):
                        navigator.cancelTask()
                        navigator.info('Failed to return to start position')
                        break

            # Rewrites back to yaml file
            points_dict = {f"point{i+1}": {"x": pt[0], "y": pt[1], "z": pt[2], "Complete": pt[3]} for i, pt in enumerate(points_list)}
            data = {"map": map, **points_dict}
            data["initial_point"] = {"initial_x": initial_x, "initial_y": initial_y, "initial_z": initial_z}
            with open(yaml_file, "w") as f:
                yaml.dump(data, f)
            break
        #Add Code Here to move to action server. 

                

    def run_pan_tilt(self, node):
        # Define Pan and Tilt Positions
        
        p_int = 0
        t_int = 0
        pan_positions = [10, 46, 82, 118, 154, 190, 226, 262, 298, 334]
        tilt_positions = [10, 30, 50, 70]

        self.mp_int += 1

        #Run code to start PT server
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
                node.hs_result= node.send_hs_goal(True, self.mp_int, p_int, t_int, self.today)
                node.visual_result = node.send_visual_goal(True, self.mp_int, p_int, t_int, self.today)
                node.ac_result = node.send_ac_goal(True, self.mp_int, p_int, t_int, self.today)
                                                                        
            
                while node.ac_result is None:
                    while node.visual_result is None:
                        while node.hs_result is None:
                            rclpy.spin_once(node, timeout_sec=5.0)
                        rclpy.spin_once(node, timeout_sec=5.0)
                    rclpy.spin_once(node, timeout_sec=5.0)
                node.hs_result = None
                node.visual_result = None
                node.ac_result = None

                
                #time.sleep(2)

            # Step down the tilt angles
            node.pt_result = node.send_pt_goal(p, 50)
            while node.pt_result is None:
                rclpy.spin_once(node)
            node.pt_result = None

            node.pt_result = node.send_pt_goal(p, 30)
            while node.pt_result is None:
                rclpy.spin_once(node)
            node.pt_result = None

            t_int = 0

        p_int = 0

        node.pt_result = node.send_pt_goal(10, 10)

    

def main():
    rclpy.init()

    inspection_route = [
        [2.17, 2.66],
        [7.2, 2.61],
        [10.7, -0.865],
        [-0.2, -1.89],
	    [0.0, 0.0]]

    # Define the node and navigator
    node = Client()
    integration = IntegrationExecutable()
    navigator = BasicNavigator('basic_navigator', 'j100_0219')

    # Run Navigation
    integration.run_navigator(navigator, inspection_route, node)
    
   

    navigator.lifecycleShutdown()


if __name__ == '__main__':
    main()
