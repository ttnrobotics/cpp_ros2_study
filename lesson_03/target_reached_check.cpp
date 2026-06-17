#include <iostream>
#include <string>
#include <cmath>

int main() {
    std::string joint_name = "joint1";

    double target_position = 1.0;
    double current_position = 0.94;
    double tolerance = 0.05;

    double position_error = target_position - current_position;
    double absolute_error = std::abs(position_error);
    
    std::cout << "Joint Name: " << joint_name << std::endl;
    std::cout << "Target Position: " << target_position << " rad" << std::endl;
    std::cout << "Current Position: " << current_position << " rad" << std::endl;

    std::cout << "Position Error: " << position_error << " rad" << std::endl;
    std::cout << "Absolute Error: " << absolute_error << " rad" << std::endl;
    std::cout << "Tolerance: " << tolerance << " rad" << std::endl;

    if (absolute_error <= tolerance){
        std::cout << "Target reached." << std::endl;
    } else {
        std::cout << "Target not reached yet." << std::endl;
    }

    return 0;
}