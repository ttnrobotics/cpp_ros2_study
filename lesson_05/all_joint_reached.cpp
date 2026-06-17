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

    double tolerance = 0.02;

    bool all_joints_reached = true;

    for ( size_t i = 0; i < joint_names.size(); i++)
    {
        double error = target_positions[i] - current_positions[i];
        double abs_error = std::abs(error);

        std::cout << joint_names[i]
                  << " | target: " << target_positions[i]
                  << " | current: " << current_positions[i]
                  << " | error: " << error
                  << " | abs error: " << abs_error
                  << std::endl;
        if (abs_error > tolerance)
        {
            all_joints_reached = false;
        }
    }

    std::cout << std::boolalpha;
    std::cout << "All joints reached: " << all_joints_reached << std::endl;

    return 0;
}