#! /usr/bin/env python3

from datetime import datetime
from actions_py.monitoring_client import Client
from geometry_msgs.msg import PoseStamped
from nav2_simple_commander.robot_navigator import BasicNavigator, TaskResult
from pdf_generator.generate_pdf import MyNode
import rclpy
import copy
from rclpy.duration import Duration
from rclpy.node import Node
import yaml
import rclpy
import numpy as np
import os
import glob
import yaml
import cv2
import jinja2
import pdfkit
import math
import itertools
from PyPDF2 import PdfMerger
from PIL import Image, ImageDraw, ImageFont
from datetime import date
from rclpy.node import Node
from pdf2image import convert_from_path
from datetime import date
import os

class IntegrationExecutable(Node):

    def __init__(self):
        super().__init__("integration_executable")
        self.mp_int = 0
        self.today = datetime.today().strftime('%d-%m-%Y_%H-%M-%S')

    def run_navigator(self, navigator, inspection_route, client, pdf_node, merger):
        yaml_file = "~/HV_monitoring/route.yaml"
        yaml_file = os.path.expanduser(yaml_file)
        # open the yaml file and load the points
        with open(yaml_file, "r") as f:
            points = yaml.safe_load(f)
 
        # Extract the x, y, and z values from the points
        points_list = [[point["x"], point["y"], point["z"], point["Complete"]] for point in points.values() if isinstance(point, dict) and "x" in point and "y" in point and "z" in point and "Complete" in point]
        
        #Loads in the map from the points.yaml file
        map_path = points["map"]
        map = os.path.expanduser(map_path)
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
                            
                self.current_pose = feedback.current_pose

                q = [
                    self.current_pose.pose.orientation.x,
                    self.current_pose.pose.orientation.y,
                    self.current_pose.pose.orientation.z,
                    self.current_pose.pose.orientation.w
                ]

                # Convert the quaternion to Euler angles
                _, _, current_yaw = self.euler_from_quaternion(q)



                # Calculate the desired yaw (90 degrees)
                desired_yaw = 1.57

                # Calculate the spin angle
                
                spin_angle = desired_yaw - current_yaw
                navigator.info(f'Quat{q[0]} {q[1]} z {q[2]} w {q[3]} ....')
                navigator.info(f'Current {current_yaw} Desired {desired_yaw} Spin {spin_angle}')
                navigator.spin(spin_angle,60)
                while not navigator.isTaskComplete():
                    feedback_spin = navigator.getFeedback()
                    if feedback_spin and i % 5==0 :
                        navigator.info(f'Spinning to angle 1.57....')
                        i+=1
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
                    if Duration.from_msg(feedback.navigation_time) > Duration(seconds=300.0):
                        navigator.goToPose(initial_pose)
                        break
                    if Duration.from_msg(feedback.navigation_time) > Duration(seconds=1000.0):
                        navigator.cancelTask()
                        navigator.info('Failed to return to start position')
                        break

            # Rewrites back to yaml file
            points_dict = {f"point{i+1}": {"x": pt[0], "y": pt[1], "z": pt[2], "Complete": pt[3]} for i, pt in enumerate(points_list)}
            data = {"map": map_path, **points_dict}
            data["initial_point"] = {"initial_x": initial_x, "initial_y": initial_y, "initial_z": initial_z}
            with open(yaml_file, "w") as f:
                yaml.dump(data, f)
            break
        self.pdf_generator(pdf_node, merger)
        #Add Code Here to move to action server. 

    def euler_from_quaternion(self, q):
        # roll (x-axis rotation)
        sinr_cosp = 2 * (q[0] * q[1] + q[2] * q[3])
        cosr_cosp = 1 - 2 * (q[1]**2 + q[2]**2)
        roll = math.atan2(sinr_cosp, cosr_cosp)

        # pitch (y-axis rotation)
        sinp = 2 * (q[0] * q[2] - q[3] * q[1])
        if abs(sinp) >= 1:
            pitch = math.copysign(math.pi / 2, sinp)  # use 90 degrees if out of range
        else:
            pitch = math.asin(sinp)

        # yaw (z-axis rotation)
        siny_cosp = 2 * (q[0] * q[3] + q[1] * q[2])
        cosy_cosp = 1 - 2 * (q[2]**2 + q[3]**2)
        yaw = math.atan2(siny_cosp, cosy_cosp)

        return roll, pitch, yaw  # in radians        

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
                                                                        
            
                while node.hs_result is None:
                    while node.visual_result is None:
                        while node.ac_result is None:
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

            t_int = 0

        p_int = 0

        node.pt_result = node.send_pt_goal(10, 10)

    
    def pdf_generator(self, node, merger):
        # Sorts all substation scan folders in order of date
        scan_folders = sorted(glob.glob('Substation_Scan_*'))
        

        # Number of rows (tilt positions) and columns (pan positions)
        x_columns = 10
        y_rows = 4

        # create the title page template and append it in the merger

        filepath = "~/HV_monitoring"
        filepath = os.path.expanduser(filepath)

        #file = os.path.join(filepath, 'maps', 'HVLab4')
        points_yaml = os.path.join(filepath, "route.yaml")
        with open(points_yaml, "r") as f:
            points = yaml.safe_load(f)
        
        filen = points['map']
        MP1 = os.path.join(filepath, 'Include', "Mp2.png")

        pdf_filename = f"Substation_Scan_{self.today}"
        scan_folder = f"{filepath}/Scans/{pdf_filename}"

        # Extract the date from the filename
        date = pdf_filename.split('_')[2:]

        # Convert the list back to a string, with elements separated by '_'
        date = '_'.join(date)

        title_pdf_page = node.title_template_creator(date)
        merger.append(title_pdf_page)
        # Sorts all monitoring point folders in order
        mp_folders = sorted(glob.glob(f'{scan_folder}/2. Monitoring Images/mp_*'))
        
        #file = os.path.join(scan_folder, '3. Map', 'substation.pgm')
        #filen = os.path.join(scan_folder, '3. Map', "HVLab")
        #points_yaml = os.path.join(scan_folder, '3. Map', "points.yaml")
        #MP1 = os.path.join(scan_folder, '3. Map', "MP1.png")
        target_x = 26.8
        target_y = -3.74
        orientation = 0.1

        # Read YAML file data
        with open(f"{filen}.yaml") as f:
            map_data = yaml.safe_load(f)
        

        points_list = [[point["x"], point["y"], point["z"]] for point in points.values() if isinstance(point, dict) and "x" in point and "y" in point and "z" in point]
        # Combine x, y, z values into a list

        # Extract resolution and origin
        resolution = map_data["resolution"]
        origin_x = map_data["origin"][0] 
        origin_y = map_data["origin"][1]
        #print(resolution)
        resolution = resolution /2
        
        # Read the image using cv2.imread() with the -1 flag for unchanged format
        image = cv2.imread(f"{filen}.pgm", -1)
        circle_image = cv2.imread(MP1, cv2.IMREAD_UNCHANGED)
        if image is None and circle_image is None:
            print(f"Error opening image: {filen}.pgm")
            exit()
        image = cv2.resize(image, None, fx=2, fy=2, interpolation=cv2.INTER_AREA)
        image = cv2.cvtColor(image, cv2.COLOR_GRAY2BGR)
        
        for point_index, pt in enumerate(points_list):
            try:
                image = node.add_point(image, circle_image, pt[0], pt[1], pt[2], resolution, origin_x, origin_y, point_index)
            except Exception as e:
                print(f"Unable to process point {pt[0]},{pt[1]}: {e}")


        # Check if image reading was successful
        
        # Display the image using cv2.imshow(
        
        #cv2.imshow("Your Image", image)
        cv2.waitKey(0)
        cv2.imwrite(f"{filen}.png", image)

        # creates the map page and append it after title
        map_pdf_page = node.map_template_creator()
        node.create_centered_pdf_map(image)
        merger.append(map_pdf_page)

        num_mp = len(mp_folders)
        #print(mp_folders)
        hotspots_pdf_page = node.hotspots_template_creator(num_mp, scan_folder, mp_folders)
        #node.create_centered_pdf_hotspots(scan_folder)
        merger.append(hotspots_pdf_page)


        # Close all open windows
        cv2.destroyAllWindows()
        #print("im here")
        for mp_folder in mp_folders:
            i = 0
            #print(mp_folder)
            # create empty arrays to store image paths
            img_path_thermal = np.empty((y_rows, x_columns), dtype=object)
            img_path_acoustic = np.empty((y_rows, x_columns), dtype=object)
            img_path_visual = np.empty((y_rows, x_columns), dtype=object)

            # saves all images in the mp folder to the respective arrays
            for x in range (1, x_columns + 1):
                for y in range(1, y_rows + 1):
                    image_filename_thermal = f"p_{x}_t_{y}.jpg"
                    image_join_thermal = os.path.join(mp_folder, 'thermal', image_filename_thermal)

                    image_therm = cv2.imread(image_join_thermal)
                    if image_therm is None:
                        print(f"Error opening thermal image: {image_join_thermal}")
                        image_therm = np.ones((480, 640, 3), dtype=np.uint8)*255
                        cv2.imwrite(image_join_thermal, image_therm)
                        #continue
                    img_path_thermal[y-1, x-1] = image_join_thermal
                    
            for x in range (1, x_columns + 1):
                for y in range(1, y_rows + 1):
                    image_filename_acoustic = f"p_{x}_t_{y}.jpg"
                    image_join_acoustic = os.path.join(mp_folder, 'acoustic', image_filename_acoustic)
                    image_ac = cv2.imread(image_join_acoustic)
                    if image_ac is None:
                        print(f"Error opening acoustic image: {image_join_acoustic}")
                        image_ac = np.ones((480, 640, 3), dtype=np.uint8)*255
                        cv2.imwrite(image_join_acoustic, image_ac)
                        #continue
                    img_path_acoustic[y-1, x-1] = image_join_acoustic

            for x in range (1, x_columns + 1):
                for y in range(1, y_rows + 1):
                    image_filename_visual = f"p_{x}_t_{y}.jpg"
                    image_join_visual = os.path.join(mp_folder, 'visual', image_filename_visual)
                    image_vis = cv2.imread(image_join_visual)
                    if image_vis is None:
                        print(f"Error opening visual image: {image_join_visual}")
                        image_vis = np.ones((480, 640, 3), dtype=np.uint8)*255
                        cv2.imwrite(image_join_visual, image_vis)
                        #continue
                    img_path_visual[y-1, x-1] = image_join_visual

            pan_angles = [0, 36, 72, 108, 144, 180, 216, 252, 288, 324]
            x = 0
            for pan in pan_angles:
                
                # Create pdf template for measurement point page
                node.template_creator(mp_folder, pan, x)

                # Check if the image paths are None before trying to create the PDF
                #if np.any(img_path_thermal[:, x] == None) or np.any(img_path_acoustic[:, x] == None) or img_path_visual[x] is None:
                    #print(f"Error: One or more image paths are None for pan angle {pan}")
                    #continue

                node.create_centered_pdf(img_path_thermal[:, x], img_path_acoustic[:, x], img_path_visual[:, x], mp_folder, pan, i)
                
                # Append the pdf template after the map page
                pdf_filename_mp = f"template_{node.mp_formatted}_pan_{pan}.pdf"
                merger.append(pdf_filename_mp)
                x += 1



        # Save PDF
        #today = date.today().strftime("%d-%m-%Y")
        pdf_report_folder = os.path.join(scan_folder, '1. PDF Report')
        if not os.path.exists(pdf_report_folder):
            os.makedirs(pdf_report_folder)
        pdf_report_path = os.path.join(pdf_report_folder, f"{pdf_filename}.pdf")
        merger.write(pdf_report_path)
        merger.close()

        # Delete all files with "template" in the filename
        for filename in glob.glob('*template*'):
            os.remove(filename)
            
        print(f"PDF saved")
    

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
    pdf_node = MyNode()
    navigator = BasicNavigator('basic_navigator', 'j100_0219')
    merger = PdfMerger()

    # Run Navigation
    integration.run_navigator(navigator, inspection_route, node, pdf_node, merger)
    
   

    navigator.lifecycleShutdown()


if __name__ == '__main__':
    main()
