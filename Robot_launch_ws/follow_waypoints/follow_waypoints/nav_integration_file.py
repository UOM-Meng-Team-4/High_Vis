#! /usr/bin/env python3
# Copyright 2021 Samsung Research America
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

from geometry_msgs.msg import PoseStamped
from nav2_simple_commander.robot_navigator import BasicNavigator, TaskResult
import rclpy
import copy
from rclpy.duration import Duration

"""
Basic navigation demo to go to poses.
"""


def main():
    rclpy.init()

    navigator = BasicNavigator('basic_navigator', 'j100_0001')
    inspection_route = [
        [2.80, 0.0],
        [26.80, -3.74],
        [26.20, -13.74],
        [26.4, -19.6],
        [25.1,-25.1],
        [12.4, -17.9],
        [9.29, -16.9],
        [0.0 , 0.0]]
    # Set our demo's initial pose
    initial_pose = PoseStamped()
    initial_pose.header.frame_id = 'map'
    initial_pose.header.stamp = navigator.get_clock().now().to_msg()
    initial_pose.pose.position.x = 0.0
    initial_pose.pose.position.y = 0.0
    initial_pose.pose.orientation.z = 0.0
    initial_pose.pose.orientation.w = 1.0
    navigator.setInitialPose(initial_pose)

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
                       
                ################################################
                #
                # Implement some code here for your application!
                #
                ################################################

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


            result = navigator.getResult()
            if result == TaskResult.SUCCEEDED:
                navigator.info('Goal succeeded!')
                current_pose  = feedback.current_pose
                navigator.info(f'Current pose {current_pose.pose.position.x}')
                #Run code to start PT server

            elif result == TaskResult.CANCELED:
                #Run Code to move to next Goal 
                
                navigator.info('Goal was canceled!')
                continue
            
            elif result == TaskResult.FAILED:
                navigator.info('Goal failed!')
                continue
            else:
                print('Goal has an invalid return status!')
            
            #Add Code Hear to move to action server. 

        navigator.lifecycleShutdown()

        #exit(0)


if __name__ == '__main__':
    main()