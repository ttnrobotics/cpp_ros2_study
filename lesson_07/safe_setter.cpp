#include<iostream>
#include<string>

class RobotController
{
public:
    RobotController()
    {
        kp_ = 8.0;
    }

    bool setKp(double kp)
    {
        if (kp <= 0.0)
        {
            std::cout << "Invalid Kp. Kp must be positive." << std::endl;
            return false;
        }

        if (kp > 100.0)
        {
            std::cout << "Invalid Kp. Kp is too large." << std::endl;
            return false;
        }

        kp_ = kp;
        return true;
    }

    double getKp()
    {
        return kp_;
    }

private:
    double kp_;

};

int main()
{
    RobotController controller;

    std::cout << "Initial Kp: " << controller.getKp() << std::endl;

    bool success1 = controller.setKp(20.0);
    std::cout << "Set Kp to 20 success: " << std::boolalpha << success1 << std::endl;
    std::cout << "Current Kp: " << controller.getKp() << std::endl;


    bool success2 = controller.setKp(-5.0);
    std::cout << "Set Kp to -5.0 success: " << std::boolalpha << success2 << std::endl;
    std::cout << "Current Kp: " << controller.getKp() << std::endl;

    bool success3 = controller.setKp(200.0);
    std::cout << "Set Kp to 20 success: " << std::boolalpha << success3 << std::endl;
    std::cout << "Current Kp: " << controller.getKp() << std::endl;

    return 0;
}