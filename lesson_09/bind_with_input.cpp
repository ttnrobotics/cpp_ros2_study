#include<functional>
#include<iostream>

class RobotController
{
public:
    void jointCallback(double joint_position)
    {
        std::cout << "Received joint position: "
                  << joint_position
                  << std::endl;
    }
};

int main()
{
    RobotController controller;

    auto callback = std::bind(
        &RobotController::jointCallback,
        &controller,
        std::placeholders::_1
    );

    callback(1.57);

    return 0;
}