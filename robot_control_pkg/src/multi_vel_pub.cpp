#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;

class VelocityPublisher : public rclcpp::Node
{
public:
  VelocityPublisher()
      : Node("velocity_publisher")
  {
    this->declare_parameter<std::string>("velocity_topic", "/turtle1/cmd_vel");
    this->declare_parameter<double>("linear_velocity", 1.0);

    this->get_parameter("velocity_topic", velocity_topic_);
    this->get_parameter("linear_velocity", linear_velocity_);

    publisher_ = this->create_publisher<geometry_msgs::msg::Twist>(velocity_topic_, 10);
    timer_ = this->create_wall_timer(100ms, std::bind(&VelocityPublisher::publish_velocity, this));

    RCLCPP_INFO(this->get_logger(), "Publishing to topic: %s with linear velocity: %.2f",
                velocity_topic_.c_str(), linear_velocity_);
  }

private:
  void publish_velocity()
  {
    auto message = geometry_msgs::msg::Twist();
    message.linear.x = linear_velocity_;
    message.angular.z = 0.0;
    publisher_->publish(message);
  }

  std::string velocity_topic_;
  double linear_velocity_;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<VelocityPublisher>());
  rclcpp::shutdown();
  return 0;
}
