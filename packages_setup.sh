cd ../
sudo rosdep init
rosdep update
rosdep install --from-paths  src --ignore-src -r -y
colcon build

echo "Every thing built perfectly"
