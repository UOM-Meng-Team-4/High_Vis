#!/usr/bin/env python3
import rclpy
import numpy as np
import os
from PIL import Image, ImageDraw, ImageFont
from datetime import date
from rclpy.node import Node
from pdf2image import convert_from_path
import jinja2
import pdfkit
from datetime import date

class MyNode(Node):

    def __init__(self):
        super().__init__("pdf_node")


    def template_creator(self):
        
        pdf_filename = "template.pdf"
        template_loader = jinja2.FileSystemLoader('./src/High_Vis/pdf_generator/pdf_generator/')
        template_env = jinja2.Environment(loader=template_loader)

        template = template_env.get_template('template.html')
        output_text = template.render()

        config = pdfkit.configuration(wkhtmltopdf='/usr/bin/wkhtmltopdf')
        options = {
            'orientation': 'Landscape',
            'page-size': 'A4',
        }
        pdfkit.from_string(output_text, pdf_filename, configuration=config, options=options)

    def create_centered_pdf(self, image_paths_thermal, image_paths_acoustic, image_paths_visual):
        pdf_template = convert_from_path("template.pdf")
        today = date.today().strftime("%Y-%m-%d")
        scaling_factor = 0.3

        # Create an A4-sized white canvas (scaled 10x)
        a4_width, a4_height = 8420, 5950
        canvas = pdf_template[0]

        # Set starting coordinates to paste images and spacing between them
        x_start, y_start = 160, 1010
        x, y = x_start, y_start
        y_ac = y_start + 145
        x_spacing = 215
        y_spacing = 300

        # Calculate number of rows and columns in image_paths
        num_rows = len(image_paths_thermal)
        num_cols = len(image_paths_thermal[0]) if num_rows > 0 else 0
        num_rows = len(image_paths_acoustic)
        num_cols = len(image_paths_acoustic[0]) if num_rows > 0 else 0


        # Paste images onto the canvas
        for row in image_paths_thermal:
            for image_path_therm in row:

                img_therm = Image.open(image_path_therm)
                original_size = img_therm.size
                new_size = (int(original_size[0] * scaling_factor), int(original_size[1] * scaling_factor))
                img_therm = img_therm.resize(new_size)
                canvas.paste(img_therm, (x, y))
                x += x_spacing
            
            x = x_start
            y -= y_spacing
        
       
        # Paste images onto the canvas
        for row in image_paths_acoustic:
            for image_path_ac in row:

                img_ac = Image.open(image_path_ac)
                original_size = img_ac.size
                new_size = (int(original_size[0] * scaling_factor), int(original_size[1] * scaling_factor))
                img_ac = img_ac.resize(new_size)
                canvas.paste(img_ac, (x, y_ac))

                x += x_spacing
            
            x = x_start
            y_ac -= y_spacing

        # Paste visual images
        y_vis = 1370
        for image_path_vis in image_paths_visual:
            img_vis = Image.open(image_path_vis)
            original_size = img_vis.size
            new_size = (int(original_size[0] * scaling_factor), int(original_size[1] * scaling_factor))
            img_vis = img_vis.resize(new_size)
            canvas.paste(img_vis, (x, y_vis))

            x += x_spacing
            

        draw = ImageDraw.Draw(canvas)

        # Get Decibel values from file
        y_ac = 310
        x = x_start + 40
        i = 0
        with open('mp_1/acoustic/avg_db_values.txt', 'r') as file:
            
            for line in file:
                    i += 1

                    if i > 10:
                        y_ac += y_spacing
                        x = x_start + 50
                        i = 0

                    else:
                        draw.text((x, y_ac), line.strip(), font=ImageFont.truetype("src/High_Vis/pdf_generator/pdf_generator/Arial.ttf", 40), fill="black")
                        x += x_spacing

        # Save as PDF with today's date
        today = date.today().strftime("%d-%m-%Y")
        pdf_filename = f"substation_scan_{today}.pdf"
        canvas.save(pdf_filename, "PDF", resolution=100.0, save_all=True)


def main(args=None):
    rclpy.init(args=args)
    node = MyNode()

    # Create pdf template
    node.template_creator()

    # Meaurement point (should be dynamic in actual code)
    mp_thermal = "mp_1/thermal"
    mp_acoustic = "mp_1/acoustic"
    mp_visual = "mp_1/visual"

    # Number of rows (tilt positions) and columns (pan positions)
    x_columns = 10
    y_rows = 4

    img_path_thermal = np.empty((y_rows, x_columns), dtype=object)
    img_path_acoustic = np.empty((y_rows, x_columns), dtype=object)
    img_path_visual = np.empty((x_columns), dtype=object)

    for x in range (1, x_columns + 1):
        for y in range(1, y_rows + 1):
            image_filename_thermal = f"p_{x}_t_{y}.jpg"
            image_join_thermal = os.path.join(mp_thermal, image_filename_thermal)
            img_path_thermal[y-1, x-1] = image_join_thermal
            
    for x in range (1, x_columns + 1):
        for y in range(1, y_rows + 1):
            image_filename_acoustic = f"p_{x}_t_{y}.jpg"
            image_join_acoustic = os.path.join(mp_acoustic, image_filename_acoustic)
            img_path_acoustic[y-1, x-1] = image_join_acoustic

    for x in range (1, x_columns + 1):
        image_filename_visual = f"p_{x}.jpg"
        image_join_visual = os.path.join(mp_visual, image_filename_visual)
        img_path_visual[x-1] = image_join_visual
    
    #today = date.today().strftime("%Y-%m-%d")
    #pdf_filename = f"substation_scan_{today}.pdf"

    node.create_centered_pdf(img_path_thermal, img_path_acoustic, img_path_visual)
    print(f"PDF saved")

    rclpy.shutdown()

if __name__ == '__main__':
    main()









