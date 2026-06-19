#include<iostream>
#include<string>

class RobotController
{
public:
    RobotController()
    {
        kp_ = 8.0;
    }

    void setKp(double kp)
    {
        kp_ = kp;
    }

    double getKp()
    {
        return kp_;
    }


    double computePCommand(double error)
    {
        return kp_ * error;
    }

private:
    double kp_;

};

int main()
{
    RobotController controller;

    std::cout << "Initial Kp: " << controller.getKp() << std::endl;

    controller.setKp(12.0);

    std::cout << "Updated Kp: " << controller.getKp() << std::endl;

    double error = 1.2;
    double command = controller.computePCommand(error);

    std::cout << "Command: " << command << std::endl;

    return 0;
}