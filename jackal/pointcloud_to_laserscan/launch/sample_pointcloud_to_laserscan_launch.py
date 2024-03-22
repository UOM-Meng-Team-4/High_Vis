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
            package='pointcloud_to_laserscan', executable='dummy_pointcloud_publisher',
            remappings=[('cloud', [LaunchConfiguration(variable_name='j100_0219'), '/cloud'])],
            parameters=[{'cloud_frame_id': 'cloud', 'cloud_extent': 2.0, 'cloud_size': 500}],
            name='cloud_publisher'
        ),
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='static_transform_publisher',
            arguments=[
                '--x', '0', '--y', '0', '--z', '0',
                '--qx', '0', '--qy', '0', '--qz', '0', '--qw', '1',
                '--frame-id', 'map', '--child-frame-id', 'cloud'
            ],
        
        ),
        Node(
            package='pointcloud_to_laserscan', executable='pointcloud_to_laserscan_node',
            remappings=[('cloud_in', [LaunchConfiguration(variable_name='j100_0219'), '/sensors/lidar3d_0/points']),
                        ('scan', [LaunchConfiguration(variable_name='j100_0219'), '/sensors/lidar2d_0/scan']),
                        ('/tf','j100_0219/tf'),
                        ( '/tf_static', 'j100_0219/tf_static')],
            parameters=[{
                'target_frame': 'lidar3d_0_laser',
                'transform_tolerance': 0.01,
                'min_height': -0.5,
                'max_height': 0.5,
                'angle_min': -3.141592,  # -M_PI/2
                'angle_max': 3.141592,  # M_PI/2
                'angle_increment': 0.00186,  # M_PI/360.0
                'scan_time': 0.02,
                'range_min': 0.9,
                'range_max': 130.0,
                'use_inf': True,
                'inf_epsilon': 1.0
            }],
            name='pointcloud_to_laserscan'
        )
    ])
