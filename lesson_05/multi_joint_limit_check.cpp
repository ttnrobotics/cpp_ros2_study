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

    std::vector<double> min_limits = {
        -2.9,
        -2.0,
        -2.5,
        -1.8
    };

    std::vector<double> max_limits = {
        2.9,
        2.0,
        2.5,
        1.8
    };

    bool all_targets_safe = true;
    std::cout << std::boolalpha;

    for ( size_t i = 0; i < joint_names.size(); i++)
    {
        bool target_inside_limit =
            target_positions[i] >= min_limits[i] &&
            target_positions[i] <= max_limits[i];

        std::cout << joint_names[i]
                  << " | target: " << target_positions[i]
                  << " | min: " << min_limits[i]
                  << " | max: " << max_limits[i]
                  << " | safe: " << target_inside_limit
                  << std::endl;
        if (!target_inside_limit)
        {
            all_targets_safe = false;
        }
    }


    std::cout << "All targets safe: " << all_targets_safe << std::endl;
    if (!all_targets_safe)
    {
        std::cout << "Montion rejected because at lest one joint target is unsafe." << std::endl;
    }
    else
    {
        std::cout << "Montion accepted." << std::endl;
    }

    return 0;
}