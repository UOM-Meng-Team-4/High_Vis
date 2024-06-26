from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()

    hotspot_node = Node(
        package = "actions_py",
        executable = "hotspot_server",
    ) 

    visual_server_node = Node(
        package = "actions_py",
        executable = "visual_cam_server",
    )

    acoustic_node = Node(
        package = "actions_py",
        executable = "ac_server",
    ) 

    pt_node = Node(
        package = "actions_py",
        executable = "pt_server",
    ) 

    thermal_camera_node = Node(
        package = "usb_cam",
        executable = "usb_cam_node_exe",
        ros_arguments = ['--remap', '__ns:=/j100_0219/sensors/thermal_cam', '--params-file', 'src/meng_team4/High_Vis/usb_cam/config/params_2.yaml']
        
    )

    visual_camera_node = Node(
        package = "usb_cam",
        executable = "usb_cam_node_exe",
        ros_arguments = ['--remap', '__ns:=/j100_0219/sensors/visual_cam', '--params-file', 'src/meng_team4/High_Vis/usb_cam/config/params_1.yaml']
    )


    ld.add_action(hotspot_node)
    ld.add_action(visual_server_node)
    ld.add_action(acoustic_node)
    ld.add_action(pt_node)
    ld.add_action(thermal_camera_node)
    ld.add_action(visual_camera_node)

    
    return ld
