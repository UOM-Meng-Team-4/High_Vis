# High_Vis
General Repository For Project

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

# Documentation for Packages

## cam_topic

### camera_topic node
Publishes an image to a topic /image_raw to simulate the thermal camera.

`ros2 run cam_topic cam_top_pub`

## pdf_generator

### pdf_gen_node node
Takes images saved in file and saves them in a pdf. This is run automatically at the end of the integration executable (IE) but there is an old version for you to do this without having to run the IE. Just change `pdf_filename` variable to the name of the substation scan folder

`ros2 run pdf_generator generate_pdf_old`

## Clients and Servers

### Servers
#### Hotspot Server
Server for taking and processing thermal images. Draws rectangle over hotspot on thermal image and colours it based on ANSI standard.
`ros2 run actions_py hotspot_server`

#### Pan/Tilt
Server to control the pan and tilt. Interfaces with microros on STM32,
`ros2 run actions_py pt_server`

#### Acoustic
Server for taking acoustic measurements. Intergaces with microros on STM32.
`ros2 run actions_py ac_server`

### Client
Filename: `monitoring_client.py`
IE uses this client to interface with the servers mentioned previously.

### Integration Executable (IE)
Integration Executable is the script that controls the overall behaviour of the robot. It acts as the overall client controlling all the of the servers responsible for navigation and monitoring. The general process is:
- Robot navigates the measurement point and stops
- Pan and tilt moves to desired position
- thermal, visual and acoustic data is taken
- Repeat until all pan and tilt angles have been completed
- Move to next measurement point
- Once finished return to origin

`ros2 run actions_py integration_executable`

### How to run integration executable on Jackal
- Run launch file (see nodes launched below): `ros2 launch actions_bringup actions.launch.py`
  - hotspot server
  - acoustic server
  - pan/tilt server
  - thermal camera node
  - visual camera node
- Ensure Navigation is prepped and running (see below)
- Run integration_executable: `ros2 run actions_py integration_executable`


## Documentation for Starting Navigation. 
All the navigation packages are found in the `/jackal/` folder.
To run mapping run: 
`ros2 launch launch_robotnav robot_launch.py params_file:=nav2_with_shim.yaml`
### Launch Robot_Launch.py Launch File
- Launches Pointcloud to Laser scan node with params for Velodyne.
- Launches Navigation 2 node with params file.
- Launches Slam node.

### Launch Local_launch.py Launch File.
`ros2 launch launch_robotnav local_launch.py`
- Launches with Localisation instead of SLAM. Requires Map Change.

### Pointcloud to laserscan package 
- Used to convert 3D Lidar in to a laserscan. configured in the previous launch files.
- https://github.com/ros-perception/pointcloud_to_laserscan/tree/rolling/launch

### Clearpath_nav2 
Custom package created from the demo packages provided by clearpath, has 3 launch files, launches slam, navigation and localisation. Appropriate launch files are launched in the above launch files. 
https://github.com/clearpathrobotics


