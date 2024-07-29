from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import ExecuteProcess

def generate_launch_description():
    turtlesim_gui = Node(
        package ='turtlesim',
        executable = 'turtlesim_node',
        name = 'turtlesim'
    )

    turtle_driver_node= Node(
        package ='robot_control_pkg',
        executable = 'spiral_motion',
        name = 'turtle_driver',
    )

    return LaunchDescription([
        turtlesim_gui,
        turtle_driver_node
    ])