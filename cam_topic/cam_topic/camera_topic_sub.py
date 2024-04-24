import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2

class MinimalSubscriber(Node):
    def __init__(self):
        super().__init__('minimal_subscriber')
        self.subscription = self.create_subscription(Image, '/image_raw', self.image_callback, 10)
        self.subscription  # Prevent unused variable warning
        self.bridge = CvBridge()

    def image_callback(self, msg):
        try:
                    # Convert ROS 2 Image message to OpenCV format
                    cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")

                    # Process the image (e.g., display it, save it, etc.)
                    # For demonstration purposes, let's display the image
                    cv2.imwrite(f"Thermal_Image_Save.jpg", cv_image)
                    #cv2.waitKey(1)  # Wait for a key press (optional)

        except Exception as e:
            self.get_logger().error(f"Error processing image: {str(e)}")

def main(args=None):
    rclpy.init(args=args)
    minimal_subscriber = MinimalSubscriber()
    rclpy.spin_once(minimal_subscriber)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
