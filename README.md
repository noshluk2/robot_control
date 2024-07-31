# 2D and 3D ROS2 Simulation
Repository Contains 2d and 3D ros simulations. Submodule is also added
### Packages
- `robot_control_pkg` : 2d tbsim simulation
- `turtlebot3` : 3D turtlebot3 simulation

### How to Run
- Create Workspace
    ```
    mkdir -p ~/rosdev_ws/src
    cd ~/rosdev_ws/src
    ```
- Clone repository
    ```
    git clone https://github.com/noshluk2/robot_control.git
    cd robot_control
    ```
- Run Bash Script , allow executive permissino to bash script
    ```
    chmod +x robot_control/packages_setup.sh
    bash robot_control/packages_setup.sh
    ```
-