#include "multi_joint_controller.hpp"

#include <cmath>
#include <iostream>

MultiJointController::MultiJointController(
    const std::string & robot_name,
    const std::vector<std::string> & joint_names,
    const std::vector<double> & min_limits,
    const std::vector<double> & max_limits,
    double kp)
: robot_name_(robot_name),
  joint_names_(joint_names),
  min_limits_(min_limits),
  max_limits_(max_limits),
  kp_(kp)
{
}

bool MultiJointController::checkVectorSizes(
    const std::vector<double> & target_positions,
    const std::vector<double> & current_positions) const
{
    return joint_names_.size() == target_positions.size() &&
           joint_names_.size() == current_positions.size() &&
           joint_names_.size() == min_limits_.size() &&
           joint_names_.size() == max_limits_.size();
}

bool MultiJointController::areTargetsSafe(
    const std::vector<double> & target_positions) const
{
    for (size_t i = 0; i < joint_names_.size(); ++i)
    {
        bool inside_limit =
            target_positions[i] >= min_limits_[i] &&
            target_positions[i] <= max_limits_[i];

        if (!inside_limit)
        {
            return false;
        }
    }

    return true;
}

std::vector<double> MultiJointController::computeErrors(
    const std::vector<double> & target_positions,
    const std::vector<double> & current_positions) const
{
    std::vector<double> errors(joint_names_.size(), 0.0);

    for (size_t i = 0; i < joint_names_.size(); ++i)
    {
        errors[i] = target_positions[i] - current_positions[i];
    }

    return errors;
}

std::vector<double> MultiJointController::computeCommands(
    const std::vector<double> & errors) const
{
    std::vector<double> commands(joint_names_.size(), 0.0);

    for (size_t i = 0; i < joint_names_.size(); ++i)
    {
        commands[i] = kp_ * errors[i];
    }

    return commands;
}

bool MultiJointController::areAllJointsReached(
    const std::vector<double> & errors,
    double tolerance) const
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

void MultiJointController::printStatus(
    const std::vector<double> & target_positions,
    const std::vector<double> & current_positions,
    const std::vector<double> & errors,
    const std::vector<double> & commands) const
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