#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;

class SpiralDriveNode : public rclcpp::Node
{
public:
  SpiralDriveNode()
      : Node("spiral_drive_node"), current_time_(0.0)
  {
    velocity_publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
    timer_ = this->create_wall_timer(100ms, std::bind(&SpiralDriveNode::publish_velocity_callback, this));
  }

private:
  void publish_velocity_callback()
  {
    auto velocity_message = geometry_msgs::msg::Twist();

    // Increase the linear velocity and angular velocity to create a spiral effect
    velocity_message.linear.x = 0.1 * current_time_;
    velocity_message.linear.y = 0.0;
    velocity_message.angular.z = 0.5;

    RCLCPP_INFO(this->get_logger(), "Moving in a Spiral: linear.x = %.2f, angular.z = %.2f",
                velocity_message.linear.x, velocity_message.angular.z);

    velocity_publisher_->publish(velocity_message);
    current_time_ += 0.1;
  }

  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr velocity_publisher_;
  double current_time_;
};

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SpiralDriveNode>());
  rclcpp::shutdown();
  return 0;
}
