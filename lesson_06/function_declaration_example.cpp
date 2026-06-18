#include<cmath>
#include<iostream>
#include<string>

double computeteError(double target, double current);
double computePCommand(double kp, double error);
bool isTargetReached(double error, double tolerance);

int main()
{
    std::string joint_name = "joint1";

    double target_position = 1.0;
    double current_position = 0.98;
    double kp = 10.0;
    double tolerance = 0.05;

    double error = computeteError(target_position, current_position);
    double command = computePCommand(kp, error);
    bool target_reached = isTargetReached(error, tolerance);

    std::cout << std::boolalpha;

    std::cout << "Joint name: " << joint_name << std::endl;
    std::cout << "Position error: " << error << std::endl;
    std::cout << "Command: " << command << std::endl;
    std::cout << "Target reached: " << target_reached << std::endl;

    return 0;
}

double computeteError(double target, double current)
{
    return target - current;
}

double computePCommand(double kp, double error)
{
    return kp * error;
}

bool isTargetReached(double error, double tolerance)
{
    return std::abs(error) < tolerance;
}
