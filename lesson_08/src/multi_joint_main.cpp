#include "multi_joint_controller.hpp"

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

    MultiJointController controller(
        "Cobot",
        joint_names,
        min_limits,
        max_limits,
        8.0);
    
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

    double tolerance = 0.05;

    if (!controller.checkVectorSizes(target_positions, current_positions))
    {
        std::cout << "Error: vector sizes do not match." << std::endl;
        return 1;
    }

    if (!controller.areTargetsSafe(target_positions))
    {
        std::cout << "Motion rejected. Target outside joint limit." << std::endl;
        return 1;
    }

    std::vector<double> errors = 
        controller.computeErrors(target_positions, current_positions);

    std::vector<double> commands =
        controller.computeCommands(errors);

    bool all_reached =
        controller.areAllJointsReached(errors, tolerance);

    controller.printStatus(
        target_positions,
        current_positions,
        errors,
        commands
    );

    std::cout << std::boolalpha;
    std::cout << "All joints reached: " << all_reached << std::endl;

    if (all_reached)
    {
        std::cout << "Final decision: Target already reached." << std::endl;
    }
    else
    {
        std::cout << "Final decision: Controller active." << std::endl;
    }

    return 0;
}