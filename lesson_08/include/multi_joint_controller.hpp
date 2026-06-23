#pragma once

#include <string>
#include <vector>

class MultiJointController
{
public:
    MultiJointController(
        const std::string & robot_name,
        const std::vector<std::string> & joint_names,
        const std::vector<double> & min_limits,
        const std::vector<double> & max_limits,
        double kp);
    
    bool checkVectorSizes(
        const std::vector<double> & target_positions,
        const std::vector<double> & current_positions) const;
    
    bool areTargetsSafe(
        const std::vector<double> & target_positions) const;
    
    std::vector<double> computeErrors(
        const std::vector<double> & target_positions,
        const std::vector<double> & current_positions) const;

    std::vector<double> computeCommands(
        const std::vector<double> & errors) const;

    bool areAllJointsReached(
        const std::vector<double> & errors,
        double tolerance) const;

    void printStatus(
        const std::vector<double> & target_positions,
        const std::vector<double> & current_positions,
        const std::vector<double> & errors,
        const std::vector<double> & commands) const;

private:
    std::string robot_name_;
    std::vector<std::string> joint_names_;
    std::vector<double> min_limits_;
    std::vector<double> max_limits_;
    double kp_;

};
