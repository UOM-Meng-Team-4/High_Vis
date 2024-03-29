import numpy as np
from PIL import Image
import random

# Define the size of the image
image_size = (480, 640)  # 100x100 pixels

# Loop through the range of x and y values
for x in range(1, 11):  # x varies from 1 to 10
    for y in range(1, 6):  # y varies from 1 to 5
        # Generate a random grayscale value
        grayscale_value = random.randint(0, 255)
        
        # Create a 2D array filled with the grayscale value
        image_array = np.full(image_size, grayscale_value, dtype=np.uint8)
        
        # Create an image from the array
        img = Image.fromarray(image_array, 'L')
        
        # Define the filename
        filename = f"p_{x}_t_{y}.jpg"
        
        # Save the image
        img.save(filename)

# Print a success message
print("Grayscale images have been successfully created and saved.")
