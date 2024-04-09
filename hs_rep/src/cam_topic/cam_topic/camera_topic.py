import rclpy
import cv2
from rclpy.node import Node

from sensor_msgs.msg import Image
from cv_bridge import CvBridge

class MinimalPublisher(Node):

    def __init__(self):
        self.bridge = CvBridge()

        super().__init__('minimal_publisher')
        
        self.image_publisher_ = self.create_publisher(Image, '/image_raw', 10)

        timer_period = 0.5  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0

    def timer_callback(self):
        # Define the path to your image file
        #image_path = 'new_test_hotspot_thermal_overlay.jpg'
        image_path = 'hotspot photos/sub_hs_3.jpg'

        # Read the image using OpenCV
        cv_image = cv2.imread(image_path)
        # Convert the OpenCV image to a ROS 2 Image message using CvBridge
        image_msg = self.bridge.cv2_to_imgmsg(cv_image, encoding="bgr8")

        # Update the header information (optional but recommended)
        image_msg.header.stamp = self.get_clock().now().to_msg()
        image_msg.header.frame_id = 'camera_frame'

        # Publish the image
        self.image_publisher_.publish(image_msg)

        # Log a message
        self.get_logger().info('Publishing image on "/image_raw"')

        # Increment the counter (if still needed)
        self.i += 1


def main(args=None):
    rclpy.init(args=args)

    minimal_publisher = MinimalPublisher()

    rclpy.spin(minimal_publisher)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    #minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
