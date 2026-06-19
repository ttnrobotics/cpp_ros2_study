#include<iostream>
#include<string>
#include<cmath>

class JointController
{
public:
    JointController(
        const std::string & joint_name,
        double kp,
        double min_limit,
        double max_limit)
    {
        joint_name_ = joint_name;
        kp_ = kp;
        min_limit_ = min_limit;
        max_limit_ = max_limit;
    }

    bool isInsideLimit(double target)
    {
        return target >= min_limit_ && target <= max_limit_;
    }

    double computeError(double target, double current)
    {
        return target - current;
    }

    double computeCommand(double error)
    {
        return kp_ * error;
    }

    bool isTargetReached(double error, double tolerance)
    {
        return std::abs(error) < tolerance;
    }

    void printInfo()
    {
        std::cout << "Joint name: " << joint_name_ << std::endl;
        std::cout << "Kp: " << kp_ << std::endl;
        std::cout << "Min limit: " << min_limit_ << std::endl;
        std::cout << "Max limit: " << max_limit_ << std::endl;
    }

private:
    std::string joint_name_;
    double kp_;
    double min_limit_;
    double max_limit_;

};

int main()
{
    JointController joint2_controller(
        "joint2",
        8.0,
        -2.0,
        2.0
    );

    double target_position = -1.2;
    double current_position = -0.9;
    double tolerance = 0.05;

    joint2_controller.printInfo();

    bool safe = joint2_controller.isInsideLimit(target_position);
    double error = joint2_controller.computeError(target_position, current_position);
    double command = joint2_controller.computeCommand(error);
    bool reached = joint2_controller.isTargetReached(error, tolerance);

    std::cout << std::boolalpha;

    std::cout << "Target position: " << target_position << std::endl;
    std::cout << "Current position: " << current_position << std::endl;
    std::cout << "Safe target: " << safe << std::endl;
    std::cout << "Error: " << error << std::endl;
    std::cout << "Command: " << command << std::endl;
    std::cout << "Target reached: " << reached << std::endl;

    return 0;
}