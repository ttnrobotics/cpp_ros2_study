#include <cmath>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string robot_name = "Cobot";

    bool robot_enabled = true;
    bool emergency_stop = false;
    bool robot_error = false;

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

    double kp = 8.0;
    double tolerance = 0.05;

    std::cout << std::boolalpha;
    std::cout << "Robot name: " << robot_name << std::endl;

    bool vector_size_ok = joint_names.size() == target_positions.size() &&
                          joint_names.size() == current_positions.size() &&
                          joint_names.size() == min_limits.size() &&
                          joint_names.size() == max_limits.size();
    if (!vector_size_ok)
    {
        std::cout << "Error: vector sizes do not match." << std::endl;
        return 1;
    }
    
    bool base_montion_allowed = 
        robot_enabled && !emergency_stop && !robot_error;

    if (!base_montion_allowed)
    {
        std::cout << "Montion blocked by robot state." << std::endl;
        return 1;
    }

    bool all_targets_safe = true;
    bool all_joints_reached = true;


    std::vector<double> control_commands(joint_names.size(), 0.0);

    for ( size_t i = 0; i < joint_names.size(); i++)
    {
        bool target_inside_limit =
            target_positions[i] >= min_limits[i] &&
            target_positions[i] <= max_limits[i];

        if (!target_inside_limit)
        {
            all_targets_safe = false;
        }

        double error = target_positions[i] - current_positions[i];
        double abs_error = std::abs(error);

        if (abs_error > tolerance)
        {
            all_joints_reached = false;
        }

        double command = kp * error;

        control_commands[i] = command;

        std::cout << joint_names[i]
                  << " | target: " << target_positions[i]
                  << " | current: " << current_positions[i]
                  << " | error: " << error
                  << " | safe: " << target_inside_limit
                  << " | command: " << command
                  << std::endl;
    }

    std::cout << "All targets safe: " << all_targets_safe << std::endl;
    std::cout << "All joints reached: " << all_joints_reached << std::endl;

    if (!all_targets_safe)
    {
        std::cout << "Controller blocked. At least one target is outside joint limits." << std::endl;
    }
    else if (all_joints_reached)
    {
        std::cout << "Robot already reached the target. No command needed." << std::endl;
    }
    else
    {
        std::cout << "Controller active. Commands are ready." << std::endl;
    }

    return 0;
}