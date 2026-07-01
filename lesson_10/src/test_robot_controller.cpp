#include"robot_controller.hpp"

#include<iostream>

int main()
{
    RobotController controller(
        "test_joint_controller",
        10.0,
        -2.0,
        2.0
    );

    double target_position = 3.0;

    bool safe = controller.isInsideLimit(target_position);

    std::cout << std::boolalpha;
    std::cout << "Target position: " << target_position << std::endl;
    std::cout << "Target safe: " << safe << std::endl;

    if (!safe)
    {
        std::cout << "Test passed: unsafe target was rejected." << std::endl;
    }
    else
    {
        std::cout << "Test failed: unsafe target was accepted." << std::endl;
    }

    return 0;
}