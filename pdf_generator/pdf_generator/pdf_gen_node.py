#!/usr/bin/env python3
import rclpy
import numpy as np
import os
from PIL import Image, ImageDraw, ImageFont
from datetime import date
from rclpy.node import Node

class MyNode(Node):

    def __init__(self):
        super().__init__("pdf_node")


    def create_centered_pdf(image_paths_thermal, image_paths_acoustic, output_file):

        today = date.today().strftime("%Y-%m-%d")

        # Create an A4-sized white canvas (scaled 10x)
        a4_width, a4_height = 8420, 5950
        canvas = Image.new("RGB", (a4_width, a4_height), color="white")

        # Set starting coordinates to paste images and spacing between them
        x_start, y_start = 500, 4800
        x, y = x_start, y_start
        y_ac = y_start + 500
        x_spacing = 750
        y_spacing = 1100

        # Calculate number of rows and columns in image_paths
        num_rows = len(image_paths_thermal)
        num_cols = len(image_paths_thermal[0]) if num_rows > 0 else 0
        num_rows = len(image_paths_acoustic)
        num_cols = len(image_paths_acoustic[0]) if num_rows > 0 else 0

         
            
        

        # Paste images onto the canvas
        for row in image_paths_thermal:
            for image_path_therm in row:

                img_therm = Image.open(image_path_therm)
                canvas.paste(img_therm, (x, y))
                x += x_spacing
            
            x = x_start
            y -= y_spacing
        
       
             # Paste images onto the canvas
        for row in image_paths_acoustic:
            for image_path_ac in row:

                img_ac = Image.open(image_path_ac)
                canvas.paste(img_ac, (x, y_ac))

                x += x_spacing
            
            x = x_start
            y_ac -= y_spacing

######## START HERE ##############
        draw = ImageDraw.Draw(canvas)
       # y_ac = y_start
        # Get Decibel values from file
        y_ac = 1070
        x = x_start + 180
        i = 0
        with open('mp_1/acoustic/avg_db_values.txt', 'r') as file:
            
            for line in file:
                    i += 1

                    if i > 10:
                        y_ac += 1100
                        x = x_start + 180
                        i = 0

                    else:
                        draw.text((x, y_ac), line.strip(), font=ImageFont.truetype("Arial.ttf", 100), fill="black")
                        x += x_spacing

       
        
        
        # Add Text
        draw = ImageDraw.Draw(canvas)
        title = f"Substation Scan {today} MP x"
        therm_text = "Thermal Images"
        ac_text = "Acoustic Data"
        therm_font = ImageFont.truetype("Arial.ttf", 120)
        ac_font = ImageFont.truetype("Arial.ttf", 120)
        title_font = ImageFont.truetype("arialbd.ttf", 180)
        title_position = (2800,70)
        therm_text_position = (200,150)
        ac_text_position = (200,2300)
       # draw.text(therm_text_position, therm_text, font=therm_font, fill="black")
        #draw.text(ac_text_position, ac_text, font=ac_font, fill="black")
        draw.text(title_position, title, font=title_font, fill="black")

        
        # Pan/Tilt Text
       # draw.text((680, 3270), "Pan 0°", font=ImageFont.truetype("Arial.ttf", 100), fill="black")
        
        '''
        # Rectangles from table
        rect_coords_list_h= [[450, 280, 1188, 3400],
                            [1188, 280, 1939, 3400],
                            [1939, 280, 2692, 3400],
                            [2692, 280, 3445, 3400],
                            [3445, 280, 4198, 3400],
                            [4198, 280, 4951, 3400],
                            [4951, 280, 5704, 3400],
                            [5704, 280, 6457, 3400],
                            [6457, 280, 7210, 3400],
                            [7210, 280, 7963, 3400]
                            ]
        
        for rect_coords_h in rect_coords_list_h:
            draw.rectangle(rect_coords_h, outline="black", width=5)

        rect_coords_list_v= [[300, 280, 7963, 850],
                            [300, 850, 7963, 1450],
                            [300, 1450, 7963, 2050],
                            [300, 2050, 7963, 2650],
                            [300, 2650, 7963, 3250],
                            ]

        for rect_coords_v in rect_coords_list_v:
            draw.rectangle(rect_coords_v, outline="black", width=5)
        '''

        rect_coords_h = [200, 280, 7963, 1445]

        for i in range(5):
            draw.rectangle(rect_coords_h, outline="black", width=5)
            rect_coords_h[1] == rect_coords_h[3]
            rect_coords_h[3] += 1100
            
            if i == 4:
                print(rect_coords_h)


        rect_coords_v = [450, 280, 1200, 6945]

        for i in range(10):
            draw.rectangle(rect_coords_v, outline="black", width=5)
            rect_coords_v[0] == rect_coords_v[2]
            rect_coords_v[2] += 750

        # Save as PDF with today's date
        pdf_filename = f"substation_scan_{today}.pdf"
        canvas.save(pdf_filename, "PDF", resolution=100.0, save_all=True)


def main(args=None):
    rclpy.init(args=args)

    # Meaurement point (should be dynamic in actual code)
    mp_thermal = "mp_1/thermal"
    mp_acoustic = "mp_1/acoustic"

    # Number of rows (tilt positions) and columns (pan positions)
    x_columns = 10
    y_rows = 5

    img_path_thermal = np.empty((y_rows, x_columns), dtype=object)
    img_path_acoustic = np.empty((y_rows, x_columns), dtype=object)

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
    
    today = date.today().strftime("%Y-%m-%d")
    pdf_filename = f"substation_scan_{today}.pdf"
    MyNode.create_centered_pdf(img_path_thermal, img_path_acoustic, pdf_filename)
    print(f"PDF saved")

    rclpy.shutdown()

if __name__ == '__main__':
    main()

  