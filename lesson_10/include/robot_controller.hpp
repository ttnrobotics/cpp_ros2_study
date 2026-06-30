#pragma once

#include <string>

class RobotController
{
public:
    RobotController(
        const std::string & robot_name,
        double kp,
        double min_limit,
        double max_limit);
    
    void printInfo() const;

    bool isInsideLimit(double target_position) const;

    double computeError(
        double target_position,
        double current_position) const;
    
    double computeCommand(double error) const;
    
private:
    std::string robot_name_;
    double kp_;
    double min_limit_;
    double max_limit_;
};

