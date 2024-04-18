from launch import LaunchDescription

from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='image_view',
            executable='image_saver',
            name='image_saver',
            remappings=[('/image', 'image_raw')],
            parameters=[
                {'_filename_format' : '~/Documents/Thermal_images/image_%04d.%s',  # Replace with your desired save directory
                'output_format': 'jpg',
                'save_all_images': 'false'
                }  # Optional: Choose image format (e.g., png, jpg)
            ]
        )
    ])
