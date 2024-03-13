# How to Make a Node in ROS2 (Python)

## Set up workspace
1) Make workspace `mkdir "workspace name"`
2) cd into workspace
3) Make source folder `mkdir src`
4) Run `Colcon Build`
5) `ls` to see if it has worked
6) Run `source install/setup.bash` 


## Create a ROS2 Python Package
1) cd to workspace in src directory
2) Run `ros2 pkg create "Name_of_package" --build-type ament_python --dependencies rclpy` (add any other dependencies here)
3) `cd ..`
4) Run `Colcon Build`

## Create a ROS2 Node (Python)
1) cd to workspace/src/package_name/package_name
2) Create new python file:  `touch "filename.py"`
3) Make it executable  `chmod +x "filename.py"`
4) `cd ../..`
5) Open python file in text editor
6) Use this template:

```ruby
#!/usr/bin/env python3

import "libraries"

class MyNode(Node):
    def __init__(self):
        super().__init__("node_name") # Change node name to what you want
        
# Create any other functions as def function_name(x, y, etc):

def main(args=None):
    rclpy.init(args=args)

    # Insert code here

    # rclpy.spin(MyNode) if you want to spin the node
    rclpy.shutdown()

if __name__ == '__main__':
    main()

```

## Get it to run as executable
1) open setup.py in package
2) In 'console_scripts' add the following between the [ ]: `"executable_name = package_name.filename:main"`
3) cd to source folder
4) Run `colcon build --symlink-install`
5) Run `source install/setup.bash`
6) To run the package type `ros2 run package_name executable_name`



