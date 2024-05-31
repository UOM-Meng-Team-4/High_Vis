import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer
from rclpy.action.server import ServerGoalHandle
from hotspot_action.action import Visual
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from datetime import date
import time
import cv2
import os

class VisualCam(Node):
    def __init__(self):
        super().__init__('visual_camera_server')

        self.filepath = "~/HV_monitoring"
        self.filepath = os.path.expanduser(self.filepath)

        self.subscription = self.create_subscription(Image, '/j100_0219/sensors/visual_cam/image_raw', self.image_callback, 10)
        self.subscription  # Prevent unused variable warning
        self.bridge = CvBridge()
    

        self.image_callback = ActionServer(self,
            Visual,
            "visual_cam_server",
            execute_callback=self.execute_callback)
        self.get_logger().info("Action Server has been started.")

    def execute_callback (self, goal_handle: ServerGoalHandle):
        target = goal_handle.request.take_visual_image
        mp = goal_handle.request.measurement_point
        pan  = goal_handle.request.pan_position
        tilt = goal_handle.request.tilt_position
        today = goal_handle.request.today

        self.get_logger().info(f"Received request to take image")

        #today = date.today().strftime("%d-%m-%Y")
        directory = os.path.join(self.filepath, "Scans", f"Substation_Scan_{today}", "2. Monitoring Images", f"mp_{mp}", "visual")
        if not os.path.exists(directory):
            os.makedirs(directory)
        
        self.visual_image_path = os.path.join(directory, f"p_{pan}_t_{tilt}.jpg")

        if target == True:
            #(1)
            VisualCam.image_processing(self)

        goal_handle.succeed()

        result = Visual.Result()
        result.visual_image_path = self.visual_image_path
        target = False
        return result

    def image_callback(self, msg):

        # Convert ROS 2 Image message to OpenCV format
        self.cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")
        
        

    def image_processing(self):
        try:
                    # Process the image (e.g., display it, save it, etc.)
                    # For demonstration purposes, let's display the image

                    cv2.imwrite(self.visual_image_path, self.cv_image)
                    print (f"Image saved at {self.visual_image_path}")
                    #cv2.waitKey(1)  # Wait for a key press (optional)

        except Exception as e:
            self.get_logger().error(f"Error processing image: {str(e)}")

def main(args=None):
    rclpy.init(args=args)
    node = VisualCam()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
