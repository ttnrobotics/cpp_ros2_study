#include<iostream>

int main()
{
    auto compute_error = [](double target, double current)
    {
        return target - current;
    };

    auto compute_command = [](double kp, double error)
    {
        return kp * error;
    };

    double target_position = 1.0;
    double current_position = 0.7;
    double kp = 8.0;

    double error = compute_error(target_position, current_position);
    double command = compute_command(kp, error);

    std::cout << "Error: " << error << std::endl;
    std::cout << "Command: " << command << std::endl;

    return 0;
}