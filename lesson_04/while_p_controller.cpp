#include <cmath>
#include <iostream>
#include <string>

int main() {
    std::string joint_name = "joint1";

    double target_position = 1.0;
    double current_position = 0.0;

    double kp = 2.0;
    double dt = 0.1;
    double tolerance = 0.0002;

    int step = 0;
    int max_steps = 50;

    double error = target_position - current_position;
    double abs_error = std::abs(error);

    std::cout << "Starting while-loop controller ..." << std::endl;

    while (abs_error > tolerance && step < max_steps){
        error = target_position - current_position;
        abs_error = std::abs(error);

        double command = kp * error;
        std::cout << "Step " << step
                  << " | current: " << current_position
                  << " | error: " << error
                  << " | command: " << command << std::endl;


        current_position += command * dt;

        ++step;
    }

    if (abs_error <= tolerance) {
        std::cout << "Target reached." << std::endl;
    } else {
        std::cout << "Stopped because max_steps reached." << std::endl;
    }

    std::cout << "Final position: " << current_position << " rad" << std::endl;

    return 0;
}