#include "robot_controller.hpp"

#include <iostream>

RobotController::RobotController(
    const std::string & robot_name,
    double kp,
    double min_limit,
    double max_limit)
: robot_name_(robot_name),
  kp_(kp),
  min_limit_(min_limit),
  max_limit_(max_limit)
{
}

void RobotController::printInfo()
{
    std::cout << "Robot name: " << robot_name_ << std::endl;
    std::cout << "Kp gain: " << kp_ << std::endl;
    std::cout << "Minimum limit: " << min_limit_ << " rad" << std::endl;
    std::cout << "Maximum limit: " << max_limit_ << " rad" << std::endl;
}

bool RobotController::setKp(double kp)
{
    if (kp <= 0)
    {
        std::cout << "Invalid Kp. Kp must be positive." << std::endl;
        return false;
    }

    if (kp > 100.0)
    {
        std::cout << "Invalid Kp. Kp is too large." << std::endl;
        return false;
    }

    kp_ = kp;
    return true;
}

double RobotController::getKp() const
{
    return kp_;
}

bool RobotController::isInsideLimit(double target_position)
{
    return target_position >= min_limit_ &&
           target_position <= max_limit_;
}

double RobotController::computeError(
    double target_position,
    double current_position)
{
    return target_position - current_position;
}

double RobotController::computeCommand(double error)
{
    return kp_ * error;
}