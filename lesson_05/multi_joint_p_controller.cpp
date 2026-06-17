#include <cmath>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> joint_names = {
        "joint1",
        "joint2",
        "joint3",
        "joint4"
    };

    std::vector<double> target_positions = {
        0.0,
        -1.0,
        0.7,
        0.3
    };

    std::vector<double> current_positions = {
        0.1,
        -0.8,
        0.5,
        0.4
    };

    double kp = 8.0;
    std::vector<double> control_commands;
    // std::vector<double> control_commands(joint_names.size(), 0.0);

    for ( size_t i = 0; i < joint_names.size(); i++)
    {
        double error = target_positions[i] - current_positions[i];
        double command = kp * error;

        control_commands.push_back(command);

        std::cout << joint_names[i]
                  << " | target: " << target_positions[i]
                  << " | current: " << current_positions[i]
                  << " | error: " << error
                  << " | command: " << command
                  << std::endl;
    }

    return 0;
}