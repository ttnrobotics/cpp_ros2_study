#include <iostream>
#include <memory>
#include <string>

class RobotController
{
public:
    RobotController(const std::string & robot_name) 
    : robot_name_(robot_name)
    {
        std::cout << "RobotController created for " << robot_name_ << std::endl;
    }

    ~RobotController()
    {
        std::cout << "RobotController destroyed for " << robot_name_ << std::endl;
    }

    void printInfo()
    {
        std::cout << "Robot name: " << robot_name_ << std::endl;
    }
private:
    std::string robot_name_;
};

int main()
{
    auto controller = std::make_shared<RobotController>("Cobot");
    controller->printInfo();

    auto joint_position = 1.57;
    auto number_of_joints = 6;
    auto robot_enabled = true;

    std::cout << "Joint position: " << joint_position << std::endl;
    std::cout << "Number of joints: " << number_of_joints << std::endl;
    std::cout << "Robot enabled: " << std::boolalpha << robot_enabled << std::endl;

    return 0;
}