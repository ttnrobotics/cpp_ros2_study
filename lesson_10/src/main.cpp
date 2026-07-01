#include "robot_controller.hpp"
#include <iostream>

int main()
{
    RobotController controller(
        "joint1_controller",
        8.0,
        -2.9,
        2.9);
    
    double target_position = 1.0;
    double current_position = 0.7;

    controller.printInfo();

    bool target_safe = controller.isInsideLimit(target_position);

    double error = controller.computeError(target_position, current_position);

    double command = controller.computeCommand(error);

    std::cout << std::boolalpha;

    std::cout << "Target position: " << target_position << " rad" << std::endl;
    std::cout << "Current position: " << current_position << " rad" << std::endl;
    std::cout << "Target safe: " << target_safe << std::endl;
    std::cout << "Position error: " << error << " rad" << std::endl;
    std::cout << "Control command: " << command << std::endl;

    return 0;
}