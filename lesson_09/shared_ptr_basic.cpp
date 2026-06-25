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
        std::cout << "RobotController destroyed for" << robot_name_ << std::endl;
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
    std::shared_ptr<RobotController> controller = 
        std::make_shared<RobotController>("Cobot");
    controller->printInfo();

    return 0;
}