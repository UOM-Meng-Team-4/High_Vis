

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
                {'filename_format' : '~/Documents/Team4_ros_ws/src/High_Vis/Thermal_Images/src/TI_Save_Folder/image_%04d.%s', 
                'output_format': 'jpg',
                'sec_per_frame': '2.0'   
                }  # Optional: Choose image format (e.g., png, jpg)
            ]
        )
    ])
