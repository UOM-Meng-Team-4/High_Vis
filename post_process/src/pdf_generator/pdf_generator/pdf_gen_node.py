#!/usr/bin/env python3
import rclpy
from PIL import Image, ImageDraw, ImageFont
from datetime import date
from rclpy.node import Node

class MyNode(Node):

    def __init__(self):
        super().__init__("pdf_node")


    def create_centered_pdf(image_paths, output_file):

        today = date.today().strftime("%Y-%m-%d")

        # Create an A4-sized white canvas
        a4_width, a4_height = 595, 842
        canvas = Image.new("RGB", (a4_width, a4_height), color="white")

        # Calculate total width of images
        total_width = sum(Image.open(img_path).width for img_path in image_paths)

        # Calculate starting x-coordinate for centering images
        #x_offset = (a4_width - total_width) // 2
        x_offset = 50
        y_offset = 100

        # Paste images onto the canvas
        for img_path in image_paths:
            img = Image.open(img_path)
            img = img.resize((100, 100), Image.LANCZOS)
            canvas.paste(img, (x_offset, y_offset))
            x_offset += img.width

        # Add "Thermal Images" text
        draw = ImageDraw.Draw(canvas)
        title = f"Substation Scan {today} MP x"
        therm_text = "Thermal Images"
        ac_text = "Acoustic Data"
        therm_font = ImageFont.truetype("Arial.ttf", 16)
        ac_font = ImageFont.truetype("Arial.ttf", 16)
        title_font = ImageFont.truetype("arialbd.ttf", 24)
        title_position = (105,20)
        therm_text_position = (50,75)
        ac_text_position = (50,225)
        draw.text(therm_text_position, therm_text, font=therm_font, fill="black")
        draw.text(ac_text_position, ac_text, font=ac_font, fill="black")
        draw.text(title_position, title, font=title_font, fill="black")

        # Draw Rectangle for Acoustic Data (Temporary)
        rect_coords = [50, 250, (595-50), (842-50)]
        draw.rectangle(rect_coords, outline = "black", width = 2)

        # Save as PDF with today's date
        pdf_filename = f"substation_scan_{today}.pdf"
        canvas.save(pdf_filename, "PDF", resolution=100.0, save_all=True)


def main(args=None):
    rclpy.init(args=args)

    # Example usage
    image_paths = ["therm1.jpg", "therm2.jpg", "therm3.jpg", "therm4.jpg", "therm5.jpg"]
    today = date.today().strftime("%Y-%m-%d")
    pdf_filename = f"substation_scan_{today}.pdf"
    MyNode.create_centered_pdf(image_paths, pdf_filename)
    print(f"PDF saved")

    #rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()