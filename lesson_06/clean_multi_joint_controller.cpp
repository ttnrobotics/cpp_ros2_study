#include<cmath>
#include<iostream>
#include<string>
#include<vector>

bool checkVectorSizes(
    const std::vector<std::string> & joint_names,
    const std::vector<double> & target_positions,
    const std::vector<double> & current_positions,
    const std::vector<double> & min_limits,
    const std::vector<double> & max_limits)
{
    return joint_names.size() == target_positions.size() &&
           joint_names.size() == current_positions.size() &&
           joint_names.size() == min_limits.size() &&
           joint_names.size() == max_limits.size();
}

bool isRobotStateSafe(
    bool robot_enabled,
    bool emergency_stop,
    bool robot_error)
{
    return robot_enabled && !emergency_stop && !robot_error;
}

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
    std::string robot_name = "OpenManipulator-X";

    bool robot_enabled = true;
    bool emergency_stop = false;
    bool robot_error = false;

    std::vector<std::string> joint_names = {
        "joint1",
        "joint2",
        "joint3",
        "joint4",
        "gripper"
    };

    std::vector<double> target_positions = {
        0.0,
        -1.0,
        0.7,
        0.3,
        0.01
    };

    std::vector<double> current_positions = {
        0.1,
        -0.8,
        0.5,
        0.4,
        0.03
    };

    std::vector<double> min_limits = {
        -2.9,
        -2.0,
        -2.5,
        -1.8,
        0.0
    };

    std::vector<double> max_limits = {
        2.9,
        2.0,
        2.5,
        1.8,
        0.04
    };

    double kp = 8.0;
    double arm_tolerance = 0.05;
    double gripper_tolerance = 0.002;

    std::cout << std::boolalpha;
    std::cout << "Robot name: " << robot_name << std::endl;

    if (!checkVectorSizes(
            joint_names,
            target_positions,
            current_positions,
            min_limits,
            max_limits))
    {
        std::cout << "Error: vector sizes do not match." << std::endl;
        return 1;
    }

    if (!isRobotStateSafe(robot_enabled, emergency_stop, robot_error))
    {
        std::cout << "Motion rejected because robot state is unsafe." << std::endl;
        return 1;
    }

    bool all_targets_safe = true;
    bool all_joints_reached = true;

    std::vector<double> control_commands(joint_names.size(), 0.0);

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

        double command = computePCommand(kp, error);

        double tolerance = arm_tolerance;

        if (joint_names[i] == "gripper")
        {
            tolerance = gripper_tolerance;
        }

        bool joint_reached = isTargetReached(error, tolerance);

        control_commands[i] = command;

        if (!target_safe)
        {
            all_targets_safe = false;
        }

        if (!joint_reached)
        {
            all_joints_reached = false;
        }

        std::cout << joint_names[i]
                  << " | target: " << target_positions[i]
                  << " | current: " << current_positions[i]
                  << " | error: " << error
                  << " | command: " << command
                  << " | safe: " << target_safe
                  << " | reached: " << joint_reached
                  << std::endl;
    }

    std::cout << "All targets safe: " << all_targets_safe << std::endl;
    std::cout << "All joints reached: " << all_joints_reached << std::endl;

    if (!all_targets_safe)
    {
        std::cout << "Final decision: Motion rejected." << std::endl;
    }
    else if (all_joints_reached)
    {
        std::cout << "Final decision: Target already reached." << std::endl;
    }
    else
    {
        std::cout << "Final decision: Controller active." << std::endl;
    }

    return 0;
}