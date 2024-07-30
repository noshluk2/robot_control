from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='robot_control_pkg',
            executable='multi_tbsim_drive',
            name='velocity_publisher_turtle2',
            parameters=[{'velocity_topic': '/turtle1/cmd_vel', 'linear_velocity': 1.0}]
        ),
        Node(
            package='robot_control_pkg',
            executable='multi_tbsim_drive',
            name='velocity_publisher_turtle3',
            parameters=[{'velocity_topic': '/turtle2/cmd_vel', 'linear_velocity': 1.0}]
        ),
        Node(
            package='robot_control_pkg',
            executable='multi_tbsim_drive',
            name='velocity_publisher_turtle3',
            parameters=[{'velocity_topic': '/turtle3/cmd_vel', 'linear_velocity': 1.0}]
        ),
    ])
