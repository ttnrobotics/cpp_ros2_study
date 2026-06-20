#include<iostream>
#include<string>
#include<cmath>
#include<vector>

class MultiJointController
{
public:
    MultiJointController(
        const std::string & robot_name,
        const std::vector<std::string> & joint_names,
        const std::vector<double>  min_limits,
        const std::vector<double> max_limits,
        double kp)
    {
        robot_name_ = robot_name;
        joint_names_ = joint_names;
        min_limits_ = min_limits;
        max_limits_ = max_limits;
        kp_ = kp;
    }

    bool checkVectorSizes(
        const std::vector<double> & target_positions,
        const std::vector<double> & current_positions)
    {
        return joint_names_.size() == target_positions.size() &&
               joint_names_.size() == current_positions.size() &&
               joint_names_.size() == min_limits_.size() &&
               joint_names_.size() == max_limits_.size();
    }

    bool areTargetSafe(const std::vector<double> & target_positions)
    {
        for (size_t i = 0; i < joint_names_.size(); ++i)
        {
            bool inside_limit = 
                target_positions[i] >= min_limits_[i] &&
                target_positions[i] <= max_limits_[i];

            if(!inside_limit)
            {
                return false;   
            }
        }

        return true;
    }
    std::vector<double> computeErrors(
        const std::vector<double> & target_positions,
        const std::vector<double> & current_positions)
    {
        std::vector<double> errors(joint_names_.size(), 0.0);

        for (size_t i = 0; i < joint_names_.size(); ++i)
        {
            errors[i] = target_positions[i] - current_positions[i];
        }

        return errors;
    }

    std::vector<double> computeCommands(
        const std::vector<double> & errors)
    {
        std::vector<double> commands(joint_names_.size(), 0.0);

        for (size_t i = 0; i < joint_names_.size(); ++i)
        {
            commands[i] = kp_ * errors[i];
        }

        return commands;
    }

    bool areAllJointsReached(
        const std::vector<double> & errors,
        double tolerance)
    {
        for (size_t i = 0; i < errors.size(); ++i)
        {
            if (std::abs(errors[i]) > tolerance)
            {
                return false;
            }
        }

        return true;
    }

    void printStatus(
        const std::vector<double> & target_positions,
        const std::vector<double> & current_positions,
        const std::vector<double> & errors,
        const std::vector<double> & commands)
    {
        std::cout << "Robot name: " << robot_name_ << std::endl;

        for (size_t i = 0; i < joint_names_.size(); ++i)
        {
            std::cout << joint_names_[i]
                      << " | target: " << target_positions[i]
                      << " | current: " << current_positions[i]
                      << " | error: " << errors[i]
                      << " | command: " << commands[i]
                      << std::endl;
        }
    }

private:
    std::string robot_name_;
    std::vector<std::string> joint_names_;
    std::vector<double> min_limits_;
    std::vector<double> max_limits_;
    double kp_;

};

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
        "Cobbot",
        joint_names,
        min_limits,
        max_limits,
        8.0
    );

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

    if(!controller.checkVectorSizes(target_positions, current_positions))
    {
        std::cout << "Error: vector sizes do not match." << std::endl;
        return 1;
    }

    if (!controller.areTargetSafe(target_positions))
    {
        std::cout << "Motion rejected. At least one target is outsude joint limits." << std::endl;
        return 1;
    }

    std::vector<double> errors = controller.computeErrors(target_positions, current_positions);

    std::vector<double> commands = controller.computeCommands(errors);

    bool all_reached = controller.areAllJointsReached(errors, tolerance);

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