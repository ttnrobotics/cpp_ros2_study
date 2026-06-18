#include<cmath>
#include<iostream>
#include<string>

double computeteError(double target, double current)
{
    return target - current;
}

bool isTargetReached(double error, double tolerance)
{
    return std::abs(error) < tolerance;
}

int main()
{
    std::string joint_name = "joint1";

    double target_position = 1.0;
    double current_position = 0.98;
    double tolerance = 0.05;

    double error = computeteError(target_position, current_position);
    bool target_reached = isTargetReached(error, tolerance);

    std::cout << std::boolalpha;

    std::cout << "Joint name: " << joint_name << std::endl;
    std::cout << "Target position: " << target_position << std::endl;
    std::cout << "Current position: " << current_position << std::endl;

    std::cout << "Position error: " << error << std::endl;
    std::cout << "Tolerance: " << tolerance << std::endl;
    std::cout << "Target reached: " << target_reached << std::endl;

    return 0;
}