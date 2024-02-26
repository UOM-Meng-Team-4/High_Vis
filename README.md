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

