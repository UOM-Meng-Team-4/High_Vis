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

        self.filepath = "~/HV_monitoring"
        self.filepath = os.path.expanduser(self.filepath)

        self.last_y = None
        self.savemp = None
        self.savei = 0

    def quaternion_to_euler(self, x, y, z, w):
        #print("quaternion_to_euler")
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
    
    def add_point(self, map_image, circle_image, target_x, target_y, orientation, resolution, origin_x, origin_y, point_index, jackal_image):
        #print("add_point")
        angle = np.rad2deg(self.quaternion_to_euler(0,0,orientation,1-orientation))
        #print("finished quarternion_to_euler")
    
        image_height, image_width = map_image.shape[:2]
        # Convert the image to grayscale (if needed)
        # PGM is already grayscale but converting explicitly ensures consistency
        

        #Lines Calculate the origin of the robot correct to the image
        image_origin_x = int(-origin_x / resolution)
        image_origin_y = int(image_height + (origin_y / resolution))
        # Calculates the centre of the image;.
        image_x = int(((target_x/resolution) + image_origin_x) )
        image_y = int((-(target_y/resolution) + image_origin_y) )

        circle_image = cv2.resize(circle_image, None, fx=0.25, fy=0.25, interpolation=cv2.INTER_AREA)
        
        

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
        flag = True
        #Gets the region the circle will be placed in the map image
        while ((image_y-circle_center_y < 0) or (image_y+circle_center_y > image_height) or (image_x-circle_center_x < 0) or (image_x+circle_center_x > image_width)):
            #print("inside while")
            if image_y-circle_center_y < 0:
                image_y += 1
                flag = False
            if image_y+circle_center_y > image_height:
                image_y -= 1
                flag = True
            if image_x-circle_center_x < 0:
                image_x += 1
            if image_x+circle_center_x > image_width:
                image_x -= 1

        #print("finished while")
        roi = map_image[image_y-circle_center_y:image_y+circle_center_y, image_x-circle_center_x:image_x+circle_center_x]    
        # Get the rotation matrix
        rotation_matrix = cv2.getRotationMatrix2D(center, angle, 1.0)

        # Perform the rotation
        rotated_circle_image = cv2.warpAffine(circle_image, rotation_matrix, (circle_image_width, circle_image_height))
        #cv2.imshow("Rotated Image", rotated_circle_image)
        #cv2.waitKey(0)
        rotated_circle_image = circle_image
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

        # Adds the Point number to the image
        text = f"MP{point_index+1}"
        # Define the position for the text
        if flag == True:
            position = (image_x, image_y-circle_center_y-10)  # (x, y)
        else:
            position = (image_x, image_y+circle_center_y+10)

        # Define the font
        font = cv2.FONT_HERSHEY_SIMPLEX
        # Define the font size
        font_scale = 0.75
        # Define the color for the text (B, G, R)
        color = (0, 0, 255)  # white
        # Define the line thickness
        thickness = 2
        # Add the text to the image
        cv2.putText(map_image, text, position, font, font_scale, color, thickness)
        #add in the jackal image
        jackal_image = cv2.resize(jackal_image, None, fx=0.4, fy=0.4, interpolation=cv2.INTER_AREA)
        jackal_image_height, jackal_image_width = jackal_image.shape[:2]
        # Calculate the top left position for the jackal image
        # Convert the jackal image to RGBA
        jackal_image = cv2.cvtColor(jackal_image, cv2.COLOR_BGR2RGBA)
        top_left_y = image_origin_y - jackal_image_height // 2
        top_left_x = image_origin_x - jackal_image_width // 2
        map_image[top_left_y:top_left_y + jackal_image_height, top_left_x:top_left_x + jackal_image_width] = jackal_image


        return map_image

    # Create template for measurement point pages
    def template_creator(self, mp, pan, x):
        #print("template_creator")
        # essentially changes the mp path to the format MPX (so it looks nicer on the pdf)
        self.mp_preformat = mp.split('/')[-1] 
        self.mp_formatted = 'MP' + self.mp_preformat.split('_')[1]
        pdf_filename = f"template_{self.mp_formatted}_pan_{pan}.pdf"
        
        # loads template.html
        templates = os.path.join(self.filepath, 'Include', 'Templates')
        template_loader = jinja2.FileSystemLoader(templates)
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
    def map_template_creator(self, date_time):
        #print("map_template_creator")
        date, time = date_time.split('_')
        pdf_filename = "map_template.pdf"

        templates = os.path.join(self.filepath, 'Include', 'Templates')
        template_loader = jinja2.FileSystemLoader(templates)
        template_env = jinja2.Environment(loader=template_loader)
        template = template_env.get_template('map_template.html')
        
        output_text = template.render(date=date)
        config = pdfkit.configuration(wkhtmltopdf='/usr/bin/wkhtmltopdf')
        options = {
            'orientation': 'Portrait',
            'page-size': 'A4',
        }
        pdfkit.from_string(output_text, pdf_filename, configuration=config, options=options)

        return pdf_filename

    # Creates template for title page
    def title_template_creator(self, date_time):
        #print("title_template_creator")
        date, time = date_time.split('_')
        time = time.replace('-', ':')
        pdf_filename = "title_template.pdf"
        templates = os.path.join(self.filepath, 'Include', 'Templates')
        template_loader = jinja2.FileSystemLoader(templates)
        template_env = jinja2.Environment(loader=template_loader)

        template = template_env.get_template('title_template.html')
        output_text = template.render(date=date, time=time, ambient=20)
        config = pdfkit.configuration(wkhtmltopdf='/usr/bin/wkhtmltopdf')
        options = {
            'orientation': 'Portrait',
            'page-size': 'A2',
        }
        pdfkit.from_string(output_text, pdf_filename, configuration=config, options=options)

        return pdf_filename
    
    def hotspots_template_creator(self, num_mp, scan_folder, mp_folders):
        #print("hotspots_template_creator") 
        pdf_filename = "hotspots_template.pdf"        
        thermal_hotspots = []
        ac_hotspots = []
        num_rows = []
        templates = os.path.join(self.filepath, 'Include', 'Templates')
        template_loader = jinja2.FileSystemLoader(templates)
        template_env = jinja2.Environment(loader=template_loader)
        i = 0
        for mp in mp_folders:
            i+=1
            j=0
            mp_formatted = mp.split('/')[-1]
            thermal_hotspots.append([])  # Add a new list for the current mp
            with open(f'{scan_folder}/2. Monitoring Images/{mp_formatted}/thermal/hotspots.txt', 'r') as file:
                for line in file:
                    j+=1
                    thermal_hotspots[i-1].append(line.strip())  # Append to the last list in thermal_hotspots
            #print(thermal_hotspots)
            ac_hotspots.append([])  # Add a new list for the current mp
            j=0
            with open(f'{scan_folder}/2. Monitoring Images/{mp_formatted}/acoustic/ac_hotspots.txt', 'r') as file:
                for line in file:
                    j+=1
                    ac_hotspots[i-1].append(line.strip())  # Append to the last list in ac_hotspots
                            
            num_rows.append(max(len(thermal_hotspots[i-1]), len(ac_hotspots[i-1]))) # Append the maximum number of elements to num_rows
            #print(num_rows)
            num_ac = len(ac_hotspots)
        

        template = template_env.get_template('hotspots_template.html')
        
        #print(num_mp)
        #print (thermal_hotspots)
        #print(ac_hotspots)
        #print(num_rows)
        #print(num_ac)
        output_text = template.render(num_measurement_points=num_mp, thermal_hotspots=thermal_hotspots, ac_hotspots = ac_hotspots, mp=num_rows)
        config = pdfkit.configuration(wkhtmltopdf='/usr/bin/wkhtmltopdf')
        options = {
            'orientation': 'Portrait',
            'page-size': 'A2',
        }
        pdfkit.from_string(output_text, pdf_filename, configuration=config, options=options)

        return pdf_filename


    # Takes the map template and pastes the map image with mps marked on it
    def create_centered_pdf_map(self, image_path):
        #print("create_centered_pdf_map")
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

    '''

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
        arial = os.path.join(self.filepath, 'Include', 'Arial.ttf')
        with open(f'{scan_folder}/2. Monitoring Images/hotspots.txt', 'r') as file:
            
            for line in file:
                i += 1
                if i <= 29:
                    draw.text((x, y), line.strip(), font=ImageFont.truetype(arial, 40), fill="black")
                    y += y_spacing
                else:
                    x_save = x
                    y = y_start_therm
                    x = x_save + 400
                    i = 0
                

        pdf_filename_hotspots = f"hotspots_template.pdf"
        canvas.save(pdf_filename_hotspots, "PDF", resolution=100.0, save_all=True)
                
    '''

    # Pastes the Thermal, Acoustic, and Visual images/data into the pdf template
    def create_centered_pdf(self, image_paths_thermal, image_paths_acoustic, image_paths_visual, mp, pan, i):
        #print("create_centered_pdf")
        # Load the pdf template (scaling factor set for images)
        pdf_template_mp = convert_from_path(f"template_{self.mp_formatted}_pan_{pan}.pdf")
        scaling_factor = 0.7
        canvas = pdf_template_mp[0]

        # Set starting coordinates to paste images and spacing between them
        x_start, y_start = 200, 200
        x, y = x_start, y_start
        x_ac = x_start + 470
        x_vis = x_ac + 470
        y_spacing = 540

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

        y = y_start

        for image_path_vis in image_paths_visual:
            img_vis = Image.open(image_path_vis)
            original_size = img_vis.size
            new_size = (int(original_size[0] * scaling_factor), int(original_size[1] * scaling_factor))
            img_vis = img_vis.resize(new_size)
            canvas.paste(img_vis, (x_vis, y))

            y+= y_spacing
        # Paste visual images onto the canvas
        #y_vis = 1370
        #x_vis = x_start + 350
        #img_vis = Image.open(image_paths_visual)
       # original_size = img_vis.size
        #new_size = (int(original_size[0] * scaling_factor), int(original_size[1] * scaling_factor))
        #img_vis = img_vis.resize(new_size)
        #canvas.paste(img_vis, (x_vis, y_vis))

        # Paste decibel values onto the greyscale acoustic images pasted before
        draw = ImageDraw.Draw(canvas)
        x_text = x_ac + 120
        y_text = y_start + 130
    

        arial = os.path.join(self.filepath, 'Include', 'Arial.ttf')
        if self.savemp == mp:
            self.i = self.savei
        else:
            self.i = 0

        with open(f'{mp}/acoustic/avg_db_values.txt', 'r') as file:
            lines = itertools.islice(file, self.i, self.i + 4)
            
            #print(lines)
            for line in lines:
                #print(line)
                # Create a new ImageDraw object with a white background for each value
                bg_width, bg_height = 200, 100  # Adjust these values as needed
                bg = Image.new('RGB', (bg_width, bg_height), 'white')
                draw_bg = ImageDraw.Draw(bg)

                # Draw the text onto the new ImageDraw object
                draw_bg.text((10, 10), line.strip(), font=ImageFont.truetype(arial, 60), fill="black")  # Adjust the coordinates as needed

                # Paste the new ImageDraw object onto the canvas
                canvas.paste(bg, (x_text, y_text))

                
                y_text += y_spacing
                x = x_start + 50
                
            self.i += 4
            self.savei = self.i
            self.savemp = mp
            

        #self.last_y = y_text
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

    

    filepath = "~/HV_monitoring"
    filepath = os.path.expanduser(filepath)

    #file = os.path.join(filepath, 'maps', 'HVLab4')
    points_yaml = os.path.join(filepath, "route.yaml")
    with open(points_yaml, "r") as f:
        points = yaml.safe_load(f)
    
    filen = points['map']
    MP1 = os.path.join(filepath, 'Include', "Mp2.png")
    jackal = os.path.join(filepath, 'Include', "jackal.png")
    pdf_filename = "Substation_Scan_03-06-2024_10-09-36"
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
    
    
    # Read the image using cv2.imread() with the -1 flag for unchanged format
    image = cv2.imread(f"{filen}.pgm", -1)
    circle_image = cv2.imread(MP1, cv2.IMREAD_UNCHANGED)
    jackal_image = cv2.imread(jackal, cv2.IMREAD_UNCHANGED)
    if image is None and circle_image is None:
        print(f"Error opening image: {filen}.pgm")
        exit()

    image_height, image_width = image.shape[:2]
    resize_factor = 1
    while image_height < 1000 and image_width < 1000:
        
        
        resize_factor += 1
        print(f"resize_factor= {resize_factor}")
        image_r = cv2.resize(image, None, fx=resize_factor, fy=resize_factor, interpolation=cv2.INTER_AREA)
        image_height, image_width = image_r.shape[:2]
        print(f"image_height = {image_height}")
        print(f"image_width = {image_width}")

    if image_width > 1360 or image_height > 1312:
        resize_factor -= 1
        print(resize_factor)
        image_r = cv2.resize(image, None, fx=resize_factor, fy=resize_factor, interpolation=cv2.INTER_AREA)
    #image = cv2.resize(image, None, fx=16, fy=16, interpolation=cv2.INTER_AREA)

    image = image_r
    resolution = resolution /resize_factor
    print(image_height)
    print(image_width)
    
    image = cv2.cvtColor(image, cv2.COLOR_GRAY2BGR)
    
    for point_index, pt in enumerate(points_list):
        try:
            image = node.add_point(image, circle_image, pt[0], pt[1], pt[2], resolution, origin_x, origin_y, point_index, jackal_image)
        except Exception as e:
            print(f"Unable to process point {pt[0]},{pt[1]}: {e}")

    #image = cv2.rotate(image, cv2.ROTATE_90_COUNTERCLOCKWISE)


    # Check if image reading was successful
    
    # Display the image using cv2.imshow(
    
    #cv2.imshow("Your Image", image)
    cv2.waitKey(0)
    cv2.imwrite(f"{filen}.png", image)

    # creates the map page and append it after title
    map_pdf_page = node.map_template_creator(date)
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

    rclpy.shutdown()

    if __name__ == '__main__':
        main()









