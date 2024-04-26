#! /usr/bin/env python3

import time
from actions_py.monitoring_client import Client
from geometry_msgs.msg import PoseStamped
from nav2_simple_commander.robot_navigator import BasicNavigator, TaskResult
import rclpy
import copy
from rclpy.duration import Duration
from rclpy.node import Node
"""
Basic navigation demo to go to poses.
"""
class IntegrationExecutable(Node):

    def __init__(self):
        super().__init__("integration_executable")
        self.mp_int = 0

    def run_navigator(self, navigator, inspection_route, client):


        initial_pose = PoseStamped()
        initial_pose.header.frame_id = 'map'
        initial_pose.header.stamp = navigator.get_clock().now().to_msg()
        initial_pose.pose.position.x = -6.06
        initial_pose.pose.position.y = -0.39
        initial_pose.pose.orientation.z = -0.98
        initial_pose.pose.orientation.w = 0.180
        #navigator.setInitialPose(initial_pose)
        
        # Activate navigation, if not autostarted. This should be called after setInitialPose()
        # or this will initialize at the origin of the map and update the costmap with bogus readings.
        # If autostart, you should `waitUntilNav2Active()` instead.
        # navigator.lifecycleStartup()

        # Wait for navigation to fully activate, since autostarting nav2
        navigator.waitUntilNav2Active()

        # Load In Correct Map below. 
        # navigator.changeMap('/path/to/map.yaml')

        # You may use the navigator to clear or obtain costmaps
        navigator.clearAllCostmaps()  # also have clearLocalCostmap() and clearGlobalCostmap()
        global_costmap = navigator.getGlobalCostmap()
        local_costmap = navigator.getLocalCostmap()
        
        while rclpy.ok():
            
            #navigator.info("Running")
            inspection_points = []
            inspection_pose = PoseStamped()
            inspection_pose.header.frame_id = 'map'
            inspection_pose.header.stamp = navigator.get_clock().now().to_msg()
            inspection_pose.pose.orientation.z = 0.0
            inspection_pose.pose.orientation.w = 1.0
            for pt in inspection_route:
                inspection_pose.pose.position.x = pt[0]
                inspection_pose.pose.position.y = pt[1]
                inspection_points.append(copy.deepcopy(inspection_pose))
                nav_start = navigator.get_clock().now()

            # set our demo's goal poses to follow
            
            path = navigator.getPath(initial_pose, inspection_points[1])
            for point in inspection_points:
                navigator.goToPose(point)
                i = 0
                while not navigator.isTaskComplete():
                
                    i = i +1
                    feedback = navigator.getFeedback()
                    

                    if feedback and i % 5==0 :
                        navigator.info('Estimated time of arrival: ' + '{0:.0f}'.format(
                        Duration.from_msg(feedback.estimated_time_remaining).nanoseconds / 1e9)
                        + ' seconds.')

                        # Some navigation timeout to demo cancellation
                        if Duration.from_msg(feedback.navigation_time) > Duration(seconds=600.0):
                            navigator.cancelTask()

                        # Some navigation request change to demo preemption
                        if Duration.from_msg(feedback.navigation_time) > Duration(seconds=18.0):
                            # Some follow waypoints request change to demo preemption
                            pass
                    
                    # Do something depending on the return code

                    self.current_pose = feedback.current_pose

                    

                self.result = navigator.getResult()
                if self.result == TaskResult.SUCCEEDED:
            
                    navigator.info('Goal succeeded!')
                    current_pose  = self.current_pose
                    navigator.info(f'Current pose {current_pose.pose.position.x}')

                    # Run Pan and Tilt
                    
                    self.run_pan_tilt(client)

                elif self.result == TaskResult.CANCELED:
                    #Run Code to move to next Goal 
                    
                    navigator.info('Goal was canceled!')
                    #continue
                
                elif self.result == TaskResult.FAILED:
                    navigator.info('Goal failed!')
                    #continue

                else:
                    print('Goal has an invalid return status!')
        
        #Add Code Hear to move to action server. 

                

    def run_pan_tilt(self, node):
        # Define Pan and Tilt Positions
        
        p_int = 0
        t_int = 0
        pan_positions = [1.0 2.0]
        tilt_positions = [1.0 2.0]

        self.mp_int += 1

        #Run code to start PT server
        for p in pan_positions:
            p_int += 1
            for t in tilt_positions:
            
                # Send pt goal
                time.sleep(2)
                node.pt_result = node.send_pt_goal(p, t)

                t_int += 1

                while node.pt_result is None:
                    rclpy.spin_once(node)

                node.pt_result = None

                # Send hs goal
                node.hs_result= node.send_hs_goal(True, self.mp_int, p_int, t_int)
                node.visual_result = node.send_visual_goal(True, self.mp_int, p_int)
                node.ac_result = node.send_ac_goal(True, self.mp_int, p_int, t_int)
                                                                        
            
                while node.hs_result is None:
                    while node.visual_result is None:
                        while node.ac_result is None:
                            rclpy.spin_once(node, timeout_sec=5.0)

                node.hs_result = None
                node.visual_result = None
                node.ac_result = None

                time.sleep(2)

            t_int = 0

        p_int = 0

    

def main():
    rclpy.init()

    inspection_route = [
<<<<<<< HEAD
    [-1.03, -0.39],
	[-0.79, -1.92],
	[1.4, -1.9],
	[0.761, 1.54]]
=======
        [-1.03, -0.39],
        [-0.79, -1.92],
        [1.4, -1.9],
        [0.761, 1.54],
        [-1.03,-0.39]]
>>>>>>> 4b18f75db552be0f73bc831f4691626fe776a3a4

    # Define the node and navigator
    node = Client()
    integration = IntegrationExecutable()
    navigator = BasicNavigator('basic_navigator', 'j100_0219')

    # Run Navigation
    integration.run_navigator(navigator, inspection_route, node)
    
   

    navigator.lifecycleShutdown()


if __name__ == '__main__':
    main()
