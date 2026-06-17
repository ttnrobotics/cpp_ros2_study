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

    std::cout << "Joint tracking errors:" << std::endl;
    for ( size_t i = 0; i < joint_names.size(); i++)
    {
        double error = target_positions[i] - current_positions[i];
        double absolute_error = std::abs(error);

        std::cout << joint_names[i]
                  << " | target: " << target_positions[i]
                  << " | current: " << current_positions[i]
                  << " | error: " << error
                  << " | abs error: " << absolute_error
                  << std::endl;
    }

    return 0;
}