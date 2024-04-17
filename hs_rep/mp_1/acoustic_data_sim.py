import random

# Define the filename to write the text into
filename = "avg_db_values.txt"

# Open the file in write mode
with open(filename, 'w') as file:
    # Initialize x and y
    x = 1
    y = 1
    
    # Loop to generate and write 50 lines (10 x 5)
    for i in range(50):
        # Generate a random integer z from 0 to 40
        z = random.randint(0, 40)
        
        # Write the formatted string to the file
        file.write(f"{z} dB\n")
        
        # Increment y, and if it's greater than 5, reset it to 1 and increment x
        y += 1
        if y > 5:
            y = 1
            x += 1

# Print a success message
print(f"Text has been successfully inserted into {filename}.")
