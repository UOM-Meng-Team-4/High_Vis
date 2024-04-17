from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument(
            name='j100_0219', default_value='j100_0219',
            description='Namespace for sample topics'
        ),
        Node(
            package='pointcloud_to_laserscan', executable='pointcloud_to_laserscan_node',
            remappings=[('cloud_in', [LaunchConfiguration(variable_name='j100_0219'), '/depth_camera/depth/color/points']),
                        ('scan', [LaunchConfiguration(variable_name='j100_0219'), '/sensors/camera_0/scan']),
                        ('/tf','j100_0219/tf'),
                        ( '/tf_static', 'j100_0219/tf_static')],
            parameters=[{
                'target_frame': 'camera_0_link',
                'transform_tolerance': 0.01,
                'min_height': -0.3,
                'max_height': 0.5,
                'angle_min': -0.785,  # -M_PI/2
                'angle_max': 0.785,  # M_PI/2
                'angle_increment': 0.005,  # M_PI/360.0
                'scan_time': 0.02,
                'range_min': 0.2,
                'range_max': 1.5,
                'use_inf': True,
                'inf_epsilon': 1.0
            }],
            name='pointcloud_to_laserscan'
        )
    ])
