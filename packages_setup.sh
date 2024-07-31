git clone --recurse-submodules https://github.com/noshluk2/robot_control.git
cd ../../
sudo rosdep init
rosdep update
rosdep install --from-paths  src --ignore-src -r -y
colcon build

echo "Every thing built perfectly"
