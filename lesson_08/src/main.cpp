#include "robot_controller.hpp"

#include <iostream>

int main()
{
    RobotController controller(
        "joint1_controller",
        8.0,
        -2.9,
        2.9,
        0.05
    );

    std::cout << "Initial Kp: " << controller.getKp() << std::endl;

    bool gain_updated = controller.setKp(12.0);

    std::cout << std::boolalpha;
    std::cout << "Gain updated: " << gain_updated << std::endl;
    std::cout << "Updated Kp: " << controller.getKp() << std::endl;

    double target_position = 1.0;
    double current_position = 0.7;

    double target_velocity = 0.0;
    double current_velocity = 0.2;

    controller.printInfo();

    bool safe = controller.isInsideLimit(target_position);
    double error = controller.computeError(
        target_position,
        current_position);
    
    double velocity_error = controller.computeVelocityError(
        target_velocity,
        current_velocity);

    double command = controller.computeCommand(error);
    double PD_command = controller.computePDCommand(error, velocity_error);

    bool target_reached = controller.isTargetReached(error);

    std::cout << std::boolalpha;

    std::cout << "Target position: " << target_position << " rad" << std::endl;
    std::cout << "Current position: " << current_position << " rad" << std::endl;
    std::cout << "Target safe: " << safe << std::endl;
    std::cout << "Position error: " << error << " rad" << std::endl;
    std::cout << "Control command: " << command << std::endl;
    std::cout << "PD Control command: " << PD_command << std::endl;
    std::cout << "Target reached: " << target_reached << std::endl;

    return 0;
}