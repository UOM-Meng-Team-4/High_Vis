#!/usr/bin/env python3
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

class MyNode(Node):

    def __init__(self):
        super().__init__("pdf_node")
        self.counter = 0
        self.i = 0

    def quaternion_to_euler(x, y, z, w):
        t0 = +2.0 * (w * x + y * z)
        t1 = +1.0 - 2.0 * (x * x + y * y)
        X = math.degrees(math.atan2(t0, t1))

        t2 = +2.0 * (w * y - z * x)
        t2 = +1.0 if t2 > +1.0 else t2
        t2 = -1.0 if t2 < -1.0 else t2
        Y = math.degrees(math.asin(t2))

        t3 = +2.0 * (w * z + x * y)
        t4 = +1.0 - 2.0 * (y * y + z * z)
        Z = math.degrees(math.atan2(t3, t4))

        return Z
    
    def add_point(self, map_image, circle_image, target_x, target_y, orientation, resolution, origin_x, origin_y):
        angle = np.rad2deg(MyNode.quaternion_to_euler(0,0,orientation,1-orientation))
        
        image_height, image_width = map_image.shape[:2]
        # Convert the image to grayscale (if needed)
        # PGM is already grayscale but converting explicitly ensures consistency
        

        #Lines Calculate the origin of the robot correct to the image
        image_origin_x = int(-origin_x / resolution)
        image_origin_y = int(image_height + (origin_y / resolution))
        # Calculates the centre of the image;.
        image_x = int(((target_x/resolution) + image_origin_x) )
        image_y = int((-(target_y/resolution) + image_origin_y) )

        circle_image = cv2.resize(circle_image, None, fx=0.1, fy=0.1, interpolation=cv2.INTER_AREA)
        height, width = circle_image.shape[:2]
        if height % 2 != 0:
            height -= 1
        if width % 2 != 0:
            width -= 1
        # Crop the image to the new dimensions
        circle_image = circle_image[:height, :width]
        circle_image_height, circle_image_width = circle_image.shape[:2]
        # Calculate the center of the image
        center = (circle_image_width // 2, circle_image_height // 2)
        circle_center_y = circle_image_height // 2
        circle_center_x = circle_image_width // 2

        #Gets the region the circle will be placed in the map image
        while ((image_y-circle_center_y < 0) or (image_y+circle_center_y > image_height) or (image_x-circle_center_x < 0) or (image_x+circle_center_x > image_width)):
            if image_y-circle_center_y < 0:
                image_y += 1
            if image_y+circle_center_y > image_height:
                image_y -= 1
            if image_x-circle_center_x < 0:
                image_x += 1
            if image_x+circle_center_x > image_width:
                image_x -= 1

        roi = map_image[image_y-circle_center_y:image_y+circle_center_y, image_x-circle_center_x:image_x+circle_center_x]    
        # Get the rotation matrix
        rotation_matrix = cv2.getRotationMatrix2D(center, angle, 1.0)

        # Perform the rotation
        rotated_circle_image = cv2.warpAffine(circle_image, rotation_matrix, (circle_image_width, circle_image_height))
        #cv2.imshow("Rotated Image", rotated_circle_image)
        #cv2.waitKey(0)
        hsv_circle_image = cv2.cvtColor(rotated_circle_image, cv2.COLOR_BGR2HSV)
        # Define range for red color in HSV
        lower_red = np.array([0, 70, 50])
        upper_red = np.array([10, 255, 255])
        # Create a mask to isolate red parts of the image
        mask = cv2.inRange(hsv_circle_image, lower_red, upper_red)

        # Bitwise-AND mask and circle_image
        red_part = cv2.bitwise_and(rotated_circle_image, rotated_circle_image, mask=mask)
        red_part = cv2.cvtColor(red_part, cv2.COLOR_BGR2BGRA)
        #cv2.imshow("Your Image",red_part)
        #cv2.waitKey(0)
        red_pixels_mask = np.all(red_part[:, :, :3] == [0, 0, 255], axis=-1)

        # Set the alpha channel of the red pixels to 255
        red_part[red_pixels_mask, 3] = 255

        roi3 = cv2.cvtColor(roi, cv2.COLOR_BGR2BGRA)
        mask = mask.astype(bool)

        roi3[mask] = red_part[mask]

        # Convert the grayscale image to RGBA
        # Convert the grayscale image to BGRA if it's not already
        if map_image.shape[2] != 4:
            map_image = cv2.cvtColor(map_image, cv2.COLOR_BGR2BGRA)

        map_image[image_y-circle_center_y:image_y+circle_center_y, image_x-circle_center_x:image_x+circle_center_x] = roi3

        return map_image

    # Create template for measurement point pages
    def template_creator(self, mp, pan, x):

        # essentially changes the mp path to the format MPX (so it looks nicer on the pdf)
        self.mp_preformat = mp.split('/')[-1] 
        self.mp_formatted = 'MP' + self.mp_preformat.split('_')[1]
        pdf_filename = f"template_{self.mp_formatted}_pan_{pan}.pdf"
        
        # loads template.html
        template_loader = jinja2.FileSystemLoader('./src/High_Vis/pdf_generator/pdf_generator/Templates')
        template_env = jinja2.Environment(loader=template_loader)
        template = template_env.get_template('mp_template.html')
        
        # renders the template
        output_text = template.render(mp=self.mp_formatted, date=date.today().strftime("%d-%m-%Y"), pan=pan, x=x+1)
        config = pdfkit.configuration(wkhtmltopdf='/usr/bin/wkhtmltopdf')
        options = {
            'orientation': 'Portrait',
            'page-size': 'A4',
        }
        pdfkit.from_string(output_text, pdf_filename, configuration=config, options=options)

        # counter for the measurement points
        self.counter += 1

        # Returns the pdf_filename
        return pdf_filename

    # Creates template for map page
    def map_template_creator(self):

        pdf_filename = "map_template.pdf"
        
        template_loader = jinja2.FileSystemLoader('./src/High_Vis/pdf_generator/pdf_generator/Templates')
        template_env = jinja2.Environment(loader=template_loader)
        template = template_env.get_template('map_template.html')
        
        output_text = template.render(date=date.today().strftime("%d-%m-%Y"))
        config = pdfkit.configuration(wkhtmltopdf='/usr/bin/wkhtmltopdf')
        options = {
            'orientation': 'Portrait',
            'page-size': 'A4',
        }
        pdfkit.from_string(output_text, pdf_filename, configuration=config, options=options)

        return pdf_filename

    # Creates template for title page
    def title_template_creator(self):
        pdf_filename = "title_template.pdf"

        template_loader = jinja2.FileSystemLoader('./src/High_Vis/pdf_generator/pdf_generator/Templates')
        template_env = jinja2.Environment(loader=template_loader)

        template = template_env.get_template('title_template.html')
        
        output_text = template.render(date=date.today().strftime("%d-%m-%Y"))
        config = pdfkit.configuration(wkhtmltopdf='/usr/bin/wkhtmltopdf')
        options = {
            'orientation': 'Portrait',
            'page-size': 'A2',
        }
        pdfkit.from_string(output_text, pdf_filename, configuration=config, options=options)

        return pdf_filename
    
    def hotspots_template_creator(self): 
        pdf_filename = "hotspots_template.pdf"

        template_loader = jinja2.FileSystemLoader('./src/High_Vis/pdf_generator/pdf_generator/Templates')
        template_env = jinja2.Environment(loader=template_loader)

        template = template_env.get_template('hotspots_template.html')
        
        output_text = template.render()
        config = pdfkit.configuration(wkhtmltopdf='/usr/bin/wkhtmltopdf')
        options = {
            'orientation': 'Portrait',
            'page-size': 'A4',
        }
        pdfkit.from_string(output_text, pdf_filename, configuration=config, options=options)

        return pdf_filename


    # Takes the map template and pastes the map image with mps marked on it
    def create_centered_pdf_map(self, image_path):
        # Load the map template and the map image
        pdf_template_map = convert_from_path("map_template.pdf")
        map_img = Image.fromarray(image_path)
        map_canvas = pdf_template_map[0]

        # Calculate the center of map_canvas and map_img
        map_canvas_center = (map_canvas.width // 2, map_canvas.height // 2)
        map_img_center = (map_img.width // 2, map_img.height // 2)

        # Calculate the top-left corner coordinates to paste map_img at the center of map_canvas
        paste_coords = (map_canvas_center[0] - map_img_center[0], (map_canvas_center[1] + 50) - map_img_center[1])

        # Paste image on the pdf template
        map_canvas.paste(map_img, paste_coords)

        # Save the pdf template
        pdf_filename_map = f"map_template.pdf"
        map_canvas.save(pdf_filename_map, "PDF", resolution=100.0, save_all=True)


    def create_centered_pdf_hotspots(self, scan_folder):
        # Load the map template and the map image
        pdf_template_map = convert_from_path("hotspots_template.pdf")
        canvas = pdf_template_map[0]

        draw = ImageDraw.Draw(canvas)
        y_start_therm = 150
        x_start_therm = 60

        x = x_start_therm
        y = y_start_therm
        y_spacing = 50
        i = 0
        with open(f'{scan_folder}/2. Monitoring Images/hotspots.txt', 'r') as file:
            
            for line in file:
                i += 1
                if i <= 29:
                    draw.text((x, y), line.strip(), font=ImageFont.truetype("src/High_Vis/pdf_generator/pdf_generator/Arial.ttf", 40), fill="black")
                    y += y_spacing
                else:
                    x_save = x
                    y = y_start_therm
                    x = x_save + 400
                    i = 0
                

        pdf_filename_hotspots = f"hotspots_template.pdf"
        canvas.save(pdf_filename_hotspots, "PDF", resolution=100.0, save_all=True)
                

    # Pastes the Thermal, Acoustic, and Visual images/data into the pdf template
    def create_centered_pdf(self, image_paths_thermal, image_paths_acoustic, image_paths_visual, mp, pan):
        
        # Load the pdf template (scaling factor set for images)
        pdf_template_mp = convert_from_path(f"template_{self.mp_formatted}_pan_{pan}.pdf")
        scaling_factor = 0.8
        canvas = pdf_template_mp[0]

        # Set starting coordinates to paste images and spacing between them
        x_start, y_start = 275, 120
        x, y = x_start, y_start
        x_ac = x_start + 700
        #x_spacing = 215
        y_spacing = 435

        # Calculate number of rows and columns in image_paths
        num_rows = len(image_paths_thermal)
        num_cols = len(image_paths_thermal[0]) if num_rows > 0 else 0
        num_rows = len(image_paths_acoustic)
        num_cols = len(image_paths_acoustic[0]) if num_rows > 0 else 0


        # Paste thermal images onto the canvas
        for image_path_therm in image_paths_thermal:
            
            img_therm = Image.open(image_path_therm)
            original_size = img_therm.size
            new_size = (int(original_size[0] * scaling_factor), int(original_size[1] * scaling_factor))
            img_therm = img_therm.resize(new_size)
            canvas.paste(img_therm, (x, y))
            #x += x_spacing
            
            #x = x_start
            y += y_spacing
        
        y_vis = y
        y = y_start

        # Paste acoustic images onto the canvas
        for image_path_ac in image_paths_acoustic:
            

            img_ac = Image.open(image_path_ac)
            original_size = img_ac.size
            new_size = (int(original_size[0] * scaling_factor), int(original_size[1] * scaling_factor))
            img_ac = img_ac.resize(new_size)
            canvas.paste(img_ac, (x_ac, y))

            #x += x_spacing
            
            #x = x_start
            y += y_spacing

        # Paste visual images onto the canvas
        #y_vis = 1370
        x_vis = x_start + 350
        img_vis = Image.open(image_paths_visual)
        original_size = img_vis.size
        new_size = (int(original_size[0] * scaling_factor), int(original_size[1] * scaling_factor))
        img_vis = img_vis.resize(new_size)
        canvas.paste(img_vis, (x_vis, y_vis))

        # Paste decibel values onto the greyscale acoustic images pasted before
        draw = ImageDraw.Draw(canvas)
        x_text = x_ac + 160
        y_text = y_start + 160
        
        with open(f'{mp}/acoustic/avg_db_values.txt', 'r') as file:
            lines = itertools.islice(file, self.i, self.i + 4)
            for line in lines:
                draw.text((x_text, y_text), line.strip(), font=ImageFont.truetype("src/High_Vis/pdf_generator/pdf_generator/Arial.ttf", 80), fill="black")
                y_text += y_spacing
                x = x_start + 50
            self.i += 4

        # Save as PDF
        pdf_filename_mp = f"template_{self.mp_formatted}_pan_{pan}.pdf"
        canvas.save(pdf_filename_mp, "PDF", resolution=100.0, save_all=True)


def main(args=None):
    rclpy.init(args=args)

    # Set up nodes
    node = MyNode()
    merger = PdfMerger()

    # Sorts all substation scan folders in order of date
    scan_folders = sorted(glob.glob('Substation_Scan_*'))
    

    # Number of rows (tilt positions) and columns (pan positions)
    x_columns = 10
    y_rows = 4

    # create the title page template and append it in the merger
    title_pdf_page = node.title_template_creator()
    merger.append(title_pdf_page)

    for scan_folder in scan_folders:
        # Sorts all monitoring point folders in order
        mp_folders = sorted(glob.glob(f'{scan_folder}/2. Monitoring Images/mp_*'))
        
        file = os.path.join(scan_folder, '3. Map', 'substation.pgm')
        filen = os.path.join(scan_folder, '3. Map', "HVLab")
        points_yaml = os.path.join(scan_folder, '3. Map', "points.yaml")
        MP1 = os.path.join(scan_folder, '3. Map', "MP1.png")
        target_x = 26.8
        target_y = -3.74
        orientation = 0.1

        # Read YAML file data
        with open(f"{filen}.yaml") as f:
            map_data = yaml.safe_load(f)
        with open(points_yaml, "r") as f:
            points = yaml.safe_load(f)

        points_list = [[point["x"], point["y"], point["z"]] for point in points.values() if isinstance(point, dict) and "x" in point and "y" in point and "z" in point]
        # Combine x, y, z values into a list

        # Extract resolution and origin
        resolution = map_data["resolution"]
        origin_x = map_data["origin"][0] 
        origin_y = map_data["origin"][1]

        resolution = resolution /2
        
        # Read the image using cv2.imread() with the -1 flag for unchanged format
        image = cv2.imread(f"{filen}.pgm", 0)
        circle_image = cv2.imread(MP1, cv2.IMREAD_UNCHANGED)
        if image is None or circle_image is None:
            print("Error opening image:", file)
            exit()
        image = cv2.resize(image, None, fx=2, fy=2, interpolation=cv2.INTER_AREA)
        image = cv2.cvtColor(image, cv2.COLOR_GRAY2BGR)
        
        for pt in points_list:
            try:
                image = node.add_point(image, circle_image, pt[0], pt[1], pt[2], resolution, origin_x, origin_y)
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
        hotspots_pdf_page = node.hotspots_template_creator()
        node.create_centered_pdf_hotspots(scan_folder)
        merger.append(hotspots_pdf_page)


        # Close all open windows
        cv2.destroyAllWindows()

        for mp_folder in mp_folders:
            
            # create empty arrays to store image paths
            img_path_thermal = np.empty((y_rows, x_columns), dtype=object)
            img_path_acoustic = np.empty((y_rows, x_columns), dtype=object)
            img_path_visual = np.empty((x_columns), dtype=object)

            # saves all images in the mp folder to the respective arrays
            for x in range (1, x_columns + 1):
                for y in range(1, y_rows + 1):
                    image_filename_thermal = f"p_{x}_t_{y}.jpg"
                    image_join_thermal = os.path.join(mp_folder, 'thermal', image_filename_thermal)
                    img_path_thermal[y-1, x-1] = image_join_thermal
                    
            for x in range (1, x_columns + 1):
                for y in range(1, y_rows + 1):
                    image_filename_acoustic = f"p_{x}_t_{y}.jpg"
                    image_join_acoustic = os.path.join(mp_folder, 'acoustic', image_filename_acoustic)
                    img_path_acoustic[y-1, x-1] = image_join_acoustic

            for x in range (1, x_columns + 1):
                image_filename_visual = f"p_{x}.jpg"
                image_join_visual = os.path.join(mp_folder, 'visual', image_filename_visual)
                img_path_visual[x-1] = image_join_visual

            pan_angles = [0, 36, 72, 108, 144, 180, 216, 252, 288, 324]
            x = 0
            for pan in pan_angles:
                
                # Create pdf template for measurement point page
                node.template_creator(mp_folder, pan, x)
                node.create_centered_pdf(img_path_thermal[:, x], img_path_acoustic[:, x], img_path_visual[x], mp_folder, pan)
                
                # Append the pdf template after the map page
                pdf_filename_mp = f"template_{node.mp_formatted}_pan_{pan}.pdf"
                merger.append(pdf_filename_mp)
                x += 1



        # Save PDF
        today = date.today().strftime("%d-%m-%Y")
        pdf_report_folder = os.path.join(scan_folder, '1. PDF Report')
        if not os.path.exists(pdf_report_folder):
            os.makedirs(pdf_report_folder)
        pdf_report_path = os.path.join(pdf_report_folder, f"substation_scan_{today}.pdf")
        merger.write(pdf_report_path)
        merger.close()
        
    print(f"PDF saved")

    rclpy.shutdown()

    if __name__ == '__main__':
        main()









