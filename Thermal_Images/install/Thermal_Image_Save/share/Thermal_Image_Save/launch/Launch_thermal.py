

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
                {'_filename_format' : '~/Documents/Team4_ros_ws/src/High_Vis/Thermal_images/image_%04d.%s', 
                'output_format': 'jpg'      
                }  # Optional: Choose image format (e.g., png, jpg)
            ]
        )
    ])
