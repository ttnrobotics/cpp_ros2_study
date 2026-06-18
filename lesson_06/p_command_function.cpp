#include<iostream>
#include<string>

double computeError(double target, double current)
{
    return target - current;
}

double computePCommand(double kp, double error)
{
    return kp * error;
}

int main()
{
    std::string joint_name = "joint1";

    double target_position = 1.0;
    double current_position = 0.7;
    double kp = 10.0;

    double error = computeError(target_position, current_position);
    double command = computePCommand(kp, error);

    std::cout << "Joint name: " << joint_name << std::endl;
    std::cout << "Target position: " << target_position << std::endl;
    std::cout << "Current position: " << current_position << std::endl;

    std::cout << "Position error: " << error << " rad" << std::endl;
    std::cout << "Kp: " << kp << std::endl;
    std::cout << "Control command: " << command << std::endl;

    return 0;
}