
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import EnvironmentVariable, LaunchConfiguration, PathJoinSubstitution

ARGUMENTS = [
    DeclareLaunchArgument('rviz', default_value='false',
                          choices=['true', 'false'], description='Start rviz.'),

    DeclareLaunchArgument('world', default_value='electrical_substation_shorten',
                          description='Gazebo World'),

    DeclareLaunchArgument('setup_path',
                          default_value=[ '//etc/clearpath/'],
                          description='Clearpath setup path'),

    DeclareLaunchArgument('use_sim_time', default_value='false',
                          choices=['true', 'false'],
                          description='use_sim_time'),

    DeclareLaunchArgument('namespace', default_value='j100_0219',
            description='Namespace for sample topics'),

    DeclareLaunchArgument('params_file',
                          default_value='nav2.yaml',
                          description='Nav2 Parameters File'),
    DeclareLaunchArgument('slam',
                          default_value='True',
                          description='Use Slam as Localisation')
]

def generate_launch_description():

    # Laserscan Node
    point_to_laser = Node(
            package='pointcloud_to_laserscan', executable='pointcloud_to_laserscan_node',
            remappings=[('cloud_in', [LaunchConfiguration(variable_name='namespace'), '/sensors/lidar3d_0/velodyne_points']),
                        ('scan', [LaunchConfiguration(variable_name='namespace'), '/sensors/lidar2d_0/scan']),
                        ('/tf','j100_0219/tf'),
                        ( '/tf_static', 'j100_0219/tf_static')],
            parameters=[{
                'target_frame': 'lidar3d_0_laser',
                'transform_tolerance': 0.01,
                'min_height': -0.3,
                'max_height': 0.2,
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
     
    #Gets Params file from Launch Config
    params_file = LaunchConfiguration('params_file')

    # Nav2 Package
    pkg_clearpath_nav2 = get_package_share_directory(
        'clearpath_nav2')
    
    # Paths
    slam_launch = PathJoinSubstitution(
        [pkg_clearpath_nav2, 'launch', 'slam.launch.py'])
    #Launch slam 
    slam = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([slam_launch]),
        launch_arguments=[
            ('use_sim_time', LaunchConfiguration('use_sim_time')),
            ('setup_path', LaunchConfiguration('setup_path'))
        ]
    )
    
    local_launch = PathJoinSubstitution(
        [pkg_clearpath_nav2, 'launch', 'localization.launch.py'])
    #Launch localization
    local = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([local_launch]),
        launch_arguments=[
            ('use_sim_time', LaunchConfiguration('use_sim_time')),
            ('setup_path', LaunchConfiguration('setup_path'))
        ]
    )
    
    nav2_launch = PathJoinSubstitution(
        [pkg_clearpath_nav2, 'launch', 'nav2_bringup.launch.py'])
    #Launch Nav2
    nav2 = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([nav2_launch]),
        launch_arguments=[
            ('use_sim_time', LaunchConfiguration('use_sim_time')),
            ('setup_path', LaunchConfiguration('setup_path')),
            ('params_file', params_file),
            ('slam', LaunchConfiguration('slam'))
        ]
    )


    ld = LaunchDescription(ARGUMENTS)
    #ld.add_action(simul)
    ld.add_action(point_to_laser)
    #ld.add_action(viz)
    ld.add_action(slam)
    #ld.add_action(local)
    ld.add_action(nav2)
    return ld
