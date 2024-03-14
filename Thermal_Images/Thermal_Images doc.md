# Documentation for Thermal_Images Workspace

## Camera_pub WS
Camera pub contains the package `cam_topic`. This package contains 2 nodes. One publishes an image saved in the source folder to a topic called `image_raw` and the other receives the image and displays it. This will allow work to be done on the thermal camera without having to plug it in.

**Publisher**
`ros2 run cam_topic cam_top_pub`

**Subscriber**
`ros2 run cam_topic cam_top_sub`
