#include<iostream>
#include<string>

double computeError(double target, double current)
{
    return target - current;
}

int main()
{
    std::string joint_name = "joint1";

    double target_position = 1.0;
    double current_position = 0.7;

    double error = computeError(target_position, current_position);

    std::cout << "Joint name: " << joint_name << std::endl;
    std::cout << "Target position: " << target_position << std::endl;
    std::cout << "Current position: " << current_position << std::endl;
    std::cout << "Position error: " << error << " rad" << std::endl;

    return 0;
}