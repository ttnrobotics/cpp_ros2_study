#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;


class FirstRobotNode : public rclcpp::Node
{
public:
    FirstRobotNode() : Node("first_robot_node")
    {
        target_position_ = 1.57;
        current_position_ = 0.0;

        timer_ = this->create_wall_timer(1000ms,
                                        std::bind(&FirstRobotNode::controlLoop, this));
        RCLCPP_INFO(this->get_logger(), "First ROS2 C++ node started.");
    }
private:
    void controlLoop()
    {
        double error = target_position_ - current_position_;
        
        current_position_ += 0.1 * error;

        RCLCPP_INFO(
            this->get_logger(),
            "target = %.3f, current = %.3f, error = %.3f",
            target_position_,
            current_position_,
            error);
    }

    double target_position_;
    double current_position_;

    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<FirstRobotNode>();

    rclcpp::spin(node);

    rclcpp::shutdown();

    return 0;
}