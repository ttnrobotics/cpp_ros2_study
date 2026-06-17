#include <iostream>
#include <string>
#include <cmath>

int main() {
    std::string robot_name = "Cobot";
    std::string joint_name = "joint2";

    bool robot_enabled = true;
    bool emergency_stop = false;
    bool robot_error = false;

    double target_position = -2.2;
    double current_position = -0.9;

    double min_limit = -2.0;
    double max_limit = 2.0;

    double kp = 8.0;
    double tolerance = 0.05;

    double position_error = target_position - current_position;
    double abs_error = std::abs(position_error);
    double control_command = kp * position_error;

    bool target_inside_limit = (target_position >= min_limit) && (target_position <= max_limit);
    bool motion_allowed = robot_enabled && !emergency_stop && !robot_error && target_inside_limit;

    std::cout << std::boolalpha;

    std::cout << "Robot Name: " << robot_name << std::endl;
    std::cout << "Joint Name: " << joint_name << std::endl;
    std::cout << "Robot Enabled: " << robot_enabled << std::endl;
    std::cout << "Emergency Stop: " << emergency_stop << std::endl;
    std::cout << "Robot Error: " << robot_error << std::endl;
    std::cout << "Target Position: " << target_position << std::endl;
    std::cout << "Motion Allowed: " << motion_allowed << std::endl;

    std::cout << "Target Position: " << target_position << std::endl;
    std::cout << "Current Position: " << current_position << std::endl;

    std::cout << "Position Error: " << position_error << std::endl;
    std::cout << "Absolute Error: " << abs_error << std::endl;

    if (!motion_allowed) {
        std::cout << "Controller blocked. No command is sent." << std::endl;
    } else if (abs_error <= tolerance) {
        std::cout << "Target already reached. No command needed." << std::endl;
    } else {
        std::cout << "Controller active." << std::endl;
        std::cout << "Control command: " << control_command << std::endl;
    }

    return 0;

}