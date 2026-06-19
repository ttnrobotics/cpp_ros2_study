#include<iostream>
#include<string>

class RobotController
{

public:
    RobotController()
    {
        robot_name_ = "Cobot";
        kp_ = 8.0;
    }

    void printRobotInfo()
    {
        std::cout << "Robot name: " << robot_name_ << std::endl;
        std::cout << "Kp gain: " << kp_ << std::endl;
    }

private:
    std::string robot_name_;
    double kp_;    
};

int main()
{
    RobotController controller;
    
    controller.printRobotInfo();

    return 0;
}


