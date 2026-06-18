#include<cmath>
#include<iostream>
#include<string>
#include<vector>

double computeError(double target, double current)
{
    return target - current;
}

double computePCommand(double kp, double error)
{
    return kp * error;
}

bool isInsideLimit(double target, double min_limit, double max_limit)
{
    return target >= min_limit && target <= max_limit;
}

bool isTargetReached(double error, double tolerance)
{
    return std::abs(error) < tolerance;
}

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

    double kp = 8.0;
    double tolerance = 0.05;

    bool vector_sizes_ok = 
        joint_names.size() == target_positions.size()&&
        joint_names.size() == current_positions.size()&&
        joint_names.size() == min_limits.size()&&
        joint_names.size() == max_limits.size();

    if (!vector_sizes_ok)
    {
        std::cout << "Error: vector sizes do not match." << std::endl;
        return 1;
    }

    bool all_targets_safe = true;
    bool all_joints_reach = true;

    std::vector<double> control_commands(joint_names.size(), 0.0);
    std::cout << std::boolalpha;

    for (size_t i = 0; i < joint_names.size(); ++i)
    {
        bool target_safe = isInsideLimit(
            target_positions[i],
            min_limits[i],
            max_limits[i]
        );

        double error = computeError(
            target_positions[i],
            current_positions[i]
        );

        bool joint_reached = isTargetReached(error, tolerance);

        double command = computePCommand(kp, error);

        control_commands[i] = command;

        if (!target_safe)
        {
            all_targets_safe = false;
        }

        if (!joint_reached)
        {
            all_joints_reach = false;
        }

        std::cout << joint_names[i]
                  << " | target: " << target_positions[i]
                  << " | current: " << current_positions[i]
                  << " | error: " << error
                  << " | safe: " << target_safe
                  << " | command: " << command
                  << std::endl;
    }

    std::cout << "All targets safe: " << all_targets_safe << std::endl;
    std::cout << "All joint reached: " << all_joints_reach << std::endl;
    
    if (!all_targets_safe)
    {
        std::cout << "Final decision: Montion rejected." << std::endl;
    }
    else if (all_joints_reach)
    {
        std::cout << "Final decision: Target already reached." << std::endl;
    }
    else
    {
        std::cout << "Final decision: Controller active." << std::endl;
    }

    return 0;
}