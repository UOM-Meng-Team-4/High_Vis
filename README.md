# High_Vis
General Repository For Project

# Please Use Own repository when working on Project code.

# Robot Launch WS
Robot_launch_ws_(src) Is Designed to be downloaded and renamed into your workspace src file. 
It Includes the following Packages: 
Clearpath Simulation and Configuration Packages
Pointcloud to Laserscan Package
launch_robotnav (Custom package for loading entire simulation)
Clearpath_nav2 (Custom Navigation package for use with the Jackal)

Also includes up to date robot.yaml file. This must be placed in ~/clearpath/ folder.

launch_robotnav once built can be used to launch the entire Simulation and Navigation with all required nodes. ch
To launch run:
``` ros2 launch launch_robotnav robot_launch.py ```


# Documentation for Harry's Packages

## cam_topic

### camera_topic node
Publishes an image to a topic /image_raw to simulate the thermal camera.

`ros2 run cam_topic cam_top_pub`

### camera_topic_sub node
Basic subscriber to the topic /image_raw to receive image. Proof of concept.

`ros2 run cam_topic cam_top_sub`

## hotspot_detection

### hs_detect_node node
Hotspot detection algorithm. Currently takes image from /image_raw topic and detects hotspot on it. It then draws a circle around the hotspot and saves the image with a new name.

`ros2 run hotspot_detection hs_node`

## pdf_generator

### pdf_gen_node node
Takes images saved in file and saves them in a pdf.

`ros2 run pdf_generator pg_node`

## Clients and Servers

### Servers
**Hotspot**
`ros2 run actions_py hotspot_server`

**Pan/Tilt**
`ros2 run actions_py pt_server`

**Acoustic**
`ros2 run actions_py ac_server`

### Client
`ros2 run actions_py monitoring_client`

### Integration Executable
`ros2 run actions_py integration_executable`

### How to run integration executable
- Run camera_topic node: `ros2 run cam_topic cam_top_pub`
- In new terminals run hotspot, acoustic, and pan/tilt servers (see run commands above)
- In a new terminal run the monitoring client: `ros2 run actions_py monitoring_client`
- In a new terminal run integration executable: `ros2 run actions_py integration_executable`

## Documentation for Starting Navigation. 
`ros2 launch launch_robotnav robot_launch.py params_file:=nav2.yaml`
### Launch Robot_Launch.py Launch File
- Launches Pointcloud to Laser scan node with params for Velodyne.
- Launches Navigation 2 node with params file.
- Launches Slam node.

### Launch Local_launch.py Launch File.
`ros2 launch launch_robotnav local_launch.py`
- Launches with Localisation instead of SLAM. Requires Map Change. 


