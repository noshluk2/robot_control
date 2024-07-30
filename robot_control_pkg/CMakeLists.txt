cmake_minimum_required(VERSION 3.8)
project(robot_control_pkg)


# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(tf2_ros REQUIRED)





add_executable(drive_node src/drive_node.cpp)
ament_target_dependencies(drive_node rclcpp std_msgs geometry_msgs)



add_executable(spiral_motion src/spiral_motion.cpp)
ament_target_dependencies(spiral_motion rclcpp std_msgs geometry_msgs)

add_executable(multi_tbsim_drive src/multi_vel_pub.cpp)
ament_target_dependencies(multi_tbsim_drive rclcpp std_msgs geometry_msgs)


install(TARGETS
spiral_motion
  drive_node
  multi_tbsim_drive
  DESTINATION lib/${PROJECT_NAME})

  install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME})



ament_package()