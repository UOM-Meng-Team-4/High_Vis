from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()

    hotspot_node = Node(
        package = "actions_py",
        executable = "hotspot_server",
    ) 

    acoustic_node = Node(
        package = "actions_py",
        executable = "ac_server",
    ) 

    pt_node = Node(
        package = "actions_py",
        executable = "pt_server",
    ) 

    ld.add_action(hotspot_node)
    ld.add_action(acoustic_node)
    ld.add_action(pt_node)
    
    return ld