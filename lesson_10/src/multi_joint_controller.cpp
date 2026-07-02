#include "robot_controller.hpp"
#include <iostream>
#include <vector>

int main()
{
    RobotController controller(
        "multi_joint_controller",
        8.0,
        -2.9,
        2.9);
    
    std::vector<double> target_position = {
        1.0,
        2.0,
        1.6,
        0.2,
        0.8};

    std::vector<double> current_position = {
        0.0,
        1.0,
        0.6,
        0.4,
        1.8};

    controller.printInfo();

    for (size_t i = 0; i < target_position.size(); i++)
    {
        double error = controller.computeError(target_position[i], current_position[i]);

        double command = controller.computeCommand(error);

        std::cout << std::boolalpha;

        std::cout << "Joint " << i << " command: " << command << std::endl;
    }
    
    return 0;
}