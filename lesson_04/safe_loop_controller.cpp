#include <cmath>
#include <iostream>
#include <string>

int main() {
    std::string robot_name = "Cobot";
    std::string joint_name = "joint2";

    bool robot_enabled = true;
    bool emergency_stop = false;
    bool robot_error = false;

    double target_position = -1.2;
    double current_position = 0.0;

    double min_limit = -2.0;
    double max_limit = 2.0;

    double kp = 2.0;
    double dt = 0.1;
    double tolerance = 0.0002;

    int max_steps = 100;

    std::cout << std::boolalpha; // print bool values as true/false

    std::cout << "Robot Name: " << robot_name << std::endl;
    std::cout << "Joint Name: " << joint_name << std::endl;

    bool target_inside_limit = 
      (target_position >= min_limit) && (target_position <= max_limit);
    
    bool motion_allowed = robot_enabled && !emergency_stop && !robot_error && target_inside_limit;

    if (!motion_allowed){
        std::cout << "Motion blocked before starting controller." << std::endl;
        std::cout << "Robot enabled: " << robot_enabled << std::endl;
        std::cout << "Emergency stop: " << emergency_stop << std::endl;
        std::cout << "Robot error: " << robot_error << std::endl;
        std::cout << "Target inside limits: " << target_inside_limit << std::endl;
        return 1;
    }

    std::cout << "Motion allowed. Starting controller..." << std::endl;

    for (int step = 0; step < max_steps; ++step){
        double error = target_position - current_position;
        double abs_error = std::abs(error);
        double command = kp * error;

        std::cout << "Step " << step
                  << " | current: " << current_position
                  << " | error: " << error
                  << " | command: " << command << std::endl;

        if (abs_error < tolerance) {
            std::cout << "Target reached." << std::endl;
            break;
        }

        if (emergency_stop){
            std::cout << "Emergency stop detected during motion!" << std::endl;
            break;
        }

        
        // Simulate an emergency stop at step 20 for demonstration
        if (step == 20){
            emergency_stop = true;
        }

        current_position += command * dt;
    }
    
    std::cout << "Final position: " << current_position << " rad" << std::endl;

    return 0;
}