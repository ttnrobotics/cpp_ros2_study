#include <cmath>
#include <iostream>
#include <string>

int main()
{
    std::string robot_name = "OpenManipulator-X";
    std::string joint_name = "gripper";

    bool robot_enabled = true;
    bool emergency_stop = false;
    bool object_detected = false;

    std::cout << std::boolalpha;

    double target_position = 0.01;
    double current_position = 0.04;

    double min_limit = 0.0;
    double max_limit = 0.04;

    double kp = 3.0;
    double dt = 0.1;
    double tolerance = 0.001;

    int max_steps = 50;

    bool target_inside_limit = 
     (target_position >= min_limit) && (target_position <= max_limit);
    
    bool montion_allowed = robot_enabled && (!emergency_stop) && target_inside_limit;

    std::cout << "Robot name: " << robot_name << std::endl;
    std::cout << "Joint name: " << joint_name << std::endl;
    std::cout << "Montion allowed: " << montion_allowed << std::endl;
    
    if (!montion_allowed)
    {
        std::cout << "Gripper montion blocked." << std::endl;
        return 1;
    }

    for (int step = 0; step < max_steps; ++step)
    {
        double error = target_position - current_position;
        double command = kp * error;

        std::cout << "Step " << step
                  << " | current: " << current_position
                  << " | error: " << error
                  << " | command: " << command << std::endl;

        if (std::abs(current_position) < 0.02)
        {
            object_detected = true;
        }

        if (object_detected)
        {
            std::cout << "Object detected. Stop closing" << std::endl;
            break;
        }
        
        current_position = current_position + command * dt;
    }

    std::cout << "Final gripper position: " << current_position << std::endl;
    std::cout << "Object detected: " << object_detected << std::endl;

    return 0;
}