from launch import LaunchDescription
from launch.actions import ExecuteProcess, TimerAction

def generate_launch_description():
    return LaunchDescription([
        ExecuteProcess(
            cmd=['ros2', 'run', 'turtlesim', 'turtlesim_node'],
            name='turtlesim_node',
            shell=True
        ),
        TimerAction(
            period=2.0,
            actions=[
                ExecuteProcess(
                    cmd=['ros2', 'service', 'call', '/spawn', 'turtlesim/srv/Spawn', '"{x: 2.0, y: 2.0, theta: 0.0, name: \'turtle2\'}"'],
                    shell=True
                ),
                ExecuteProcess(
                    cmd=['ros2', 'service', 'call', '/spawn', 'turtlesim/srv/Spawn', '"{x: 8.0, y: 8.0, theta: 0.0, name: \'turtle3\'}"'],
                    shell=True
                ),
            ],
        ),
    ])
