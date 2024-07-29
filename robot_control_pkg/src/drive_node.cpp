#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int16.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;

class DriveNode : public rclcpp::Node
{
public:
  DriveNode()
      : Node("driving_node_tbsim"), count_(0)
  {
    cmd_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
    timer_ = this->create_wall_timer(500ms, std::bind(&DriveNode::timer_callback, this));
  }

private:
  void timer_callback()
  {
    auto message = geometry_msgs::msg::Twist();

    message.linear.x = 0.5;
    message.linear.y = 0.0;
    message.angular.z = 0.0;

    RCLCPP_INFO(this->get_logger(), "Go Straight");
    cmd_pub_->publish(message);
  }

  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_pub_;
  size_t count_;
};

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<DriveNode>());
  rclcpp::shutdown();
  return 0;
}