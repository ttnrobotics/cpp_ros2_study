#include <iostream>
#include <string>
#include <cmath>

int main() {
    std::string joint_name = "joint1";

    double target_position = 1.0;
    double current_position = 0.0;
    
    double kp = 2.0;
    double dt = 0.1;
    double tolerance = 0.001;

    int max_steps = 50;

    std::cout << "Joint Name: " << joint_name << std::endl;
    std::cout << "Target Position: " << target_position << " rad" << std::endl;
    std::cout << "Initial Position: " << current_position << " rad" << std::endl;

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

        current_position += command * dt;
    }

    std::cout << "Final position: " << current_position << " rad" << std::endl;


    return 0;
}