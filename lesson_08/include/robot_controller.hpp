#pragma once

#include <string>

class RobotController
{
public:
    RobotController(
        const std::string & robot_name,
        double kp,
        double min_limit,
        double max_limit,
        double tolerance);

    void printInfo();

    bool setKp(double kp);

    double getKp() const;

    bool isInsideLimit(double target_position);

    double computeError(
        double target_position,
        double current_position);
    
    double computeVelocityError(
        double target_velocity,
        double current_velocity) const;

    double computeCommand(double error);

    double computePDCommand(
        double position_error,
        double velocity_error) const;

    bool isTargetReached(double error) const;

private:
    std::string robot_name_;
    double kp_;
    double kd_;
    double min_limit_;
    double max_limit_;
    double tolerance_;
};