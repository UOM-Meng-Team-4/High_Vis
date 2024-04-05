#!/usr/bin/env python3
# action_client.py
import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from my_robot_interfaces.action import MyAction  # Replace with your actual action

class MyActionClient(Node):
    def __init__(self):
        super().__init__('my_action_client')
        self._action_client = ActionClient(self, MyAction, 'my_action')

    def send_goal(self, command):
        goal_msg = MyAction.Goal()
        goal_msg.order = command  # Your goal message here
        self._action_client.wait_for_server()
        self._send_goal_future = self._action_client.send_goal_async(goal_msg, feedback_callback=self.feedback_callback)
        self._send_goal_future.add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info('Goal rejected :(')
            return
        self.get_logger().info('Goal accepted :)')
        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.get_result_callback)

    def feedback_callback(self, feedback_msg):
        feedback = feedback_msg.feedback
        self.get_logger().info(f'Received feedback: {feedback.partial_sequence}')

    def get_result_callback(self, future):
        result = future.result().result
        self.get_logger().info(f'Result: {result.sequence}')
        rclpy.shutdown()

def main(args=None):
    rclpy.init(args=args)
    action_client = MyActionClient()
    action_client.send_goal('ros2 launch launch_robotnav robot_launch.py')
    rclpy.spin(action_client)

if __name__ == '__main__':
    main()
