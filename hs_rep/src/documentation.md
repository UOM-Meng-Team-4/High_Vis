# Documentation for HS Packages

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

## Hotspot Action Server

### Servers
**Hotspot**
`ros2 run actions_py hotspot_server`

**Navigation**
`ros2 run actions_py nav_server`

### Client

`ros2 run actions_py overall_client`

