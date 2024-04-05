#!/usr/bin/env python3
# action_server.py
import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node
from my_robot_interfaces.action import MyAction  # Replace with your actual action

class MyActionServer(Node):
    def __init__(self):
        super().__init__('my_action_server')
        self._action_server = ActionServer(
            self,
            MyAction,
            'my_action',
            self.execute_callback)

    def execute_callback(self, goal_handle):
        self.get_logger().info('Executing goal...')
        # Your goal execution logic here
        feedback_msg = MyAction.Feedback()
        feedback_msg.partial_sequence = # Your feedback data here
        goal_handle.publish_feedback(feedback_msg)
        result = MyAction.Result()
        result.sequence = # Your result data here
        return result

def main(args=None):
    rclpy.init(args=args)
    action_server = MyActionServer()
    rclpy.spin(action_server)
    action_server.destroy()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
