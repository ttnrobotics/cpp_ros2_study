#include<iostream>
#include<string>

class RobotController
{
private:
    double kp_;
public:
    RobotController(double kp)
    {
        kp_ = kp;
    }

    ~RobotController()
    {
        std::cout << "RobotController destroyed!" << std::endl;
    }

    double computeError(double target, double current)
    {
        return target - current;
    }

    double computePCommand(double error)
    {
        return kp_ * error;
    }

    void printGain()
    {
        std::cout << "Kp gain: " << kp_ << std::endl;
    }

};

int main()
{
    RobotController controller(10.0);

    double target_position = 1.0;
    double current_position = 0.7;

    double error = controller.computeError(target_position, current_position);
    double command = controller.computePCommand(error);

    controller.printGain();

    std::cout << "Error: " << error << std::endl;
    std::cout << "Command: " << command << std::endl;

    return 0;
}