#include<iostream>
#include<string>

class RobotController
{
private:
    double kp_;
public:
    RobotController()
    {
        kp_ = 8.0;
    }

    double computeError(double target, double current)
    {
        return target - current;
    }

    double computePCommand(double error)
    {
        return kp_ * error;
    }
};

int main()
{
    RobotController controller;

    double target_position = 1.0;
    double current_position = 0.7;

    double error = controller.computeError(target_position, current_position);
    double command = controller.computePCommand(error);

    std::cout << "Target position: " << target_position << " rad" << std::endl;
    std::cout << "Current position: " << current_position << " rad" << std::endl;
    std::cout << "Position error: " << error <<" rad" << std::endl;
    std::cout << "Control command: " << command << std::endl;

    return 0;
}