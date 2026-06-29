#include <functional>
#include <iostream>

class RobotController
{
private:
    /* data */
public:
    void controlLoop()
    {
        std::cout << "Control loop running..." << std::endl;
    }
};

int main()
{
    RobotController controller;

    auto callback = std::bind(
        &RobotController::controlLoop,
        &controller);
    
    callback();

    return 0;
}

