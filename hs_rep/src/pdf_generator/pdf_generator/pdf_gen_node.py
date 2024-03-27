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


    def create_centered_pdf(measurement_point, image_paths, output_file):

        today = date.today().strftime("%Y-%m-%d")

        # Create an A4-sized white canvas
        #a4_width, a4_height = 4463, 6315
        a4_width, a4_height = 8420, 5950
        canvas = Image.new("RGB", (a4_width, a4_height), color="white")

        # Calculate total width of images
        #total_width = 640*5

        # Calculate starting x-coordinate for centering images
        #x_offset = (a4_width - total_width) // 2
        x_start, y_start = 500, 2700
        x, y = x_start, y_start
        x_spacing = 750
        y_spacing = 600

        num_rows = len(image_paths)
        num_cols = len(image_paths[0]) if num_rows > 0 else 0
        

        # Paste images onto the canvas
        for row in image_paths:
            for image_path in row:
                img = Image.open(image_path)
                #img = img.resize((200, 200), Image.LANCZOS)
                canvas.paste(img, (x, y))
                x += x_spacing
            
            x = x_start
            y -= y_spacing

        
        # Add "Thermal Images" text
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
        draw.text(therm_text_position, therm_text, font=therm_font, fill="black")
        #draw.text(ac_text_position, ac_text, font=ac_font, fill="black")
        draw.text(title_position, title, font=title_font, fill="black")

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

        # Draw Rectangle for Acoustic Data (Temporary)
        #rect_coords = [200, 2500, (a4_width-200), (a4_height-200)]
        #draw.rectangle(rect_coords, outline = "black", width = 5)

        draw.text((680, 3270), "Pan 0°", font=ImageFont.truetype("Arial.ttf", 100), fill="black")
        


        # Save as PDF with today's date
        pdf_filename = f"substation_scan_{today}.pdf"
        canvas.save(pdf_filename, "PDF", resolution=100.0, save_all=True)


def main(args=None):
    rclpy.init(args=args)

    # Example usage
    mp = "mp_1"

    x_columns = 10
    y_rows = 5

    img_path = np.empty((y_rows, x_columns), dtype=object)

    for x in range (1, x_columns + 1):
        for y in range(1, y_rows + 1):
            image_filename = f"p_{x}_t_{y}.jpg"
            image_join = os.path.join(mp, image_filename)
            img_path[y-1, x-1] = image_join
    
    today = date.today().strftime("%Y-%m-%d")
    pdf_filename = f"substation_scan_{today}.pdf"
    MyNode.create_centered_pdf(mp, img_path, pdf_filename)
    print(f"PDF saved")

    #rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()

  