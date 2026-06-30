#include <chrono>
#include <iostream>
#include <functional>
#include <memory>
#include <string>
#include <thread>
#include <vector>

class RobotController
{
private:
    std::string robot_name_;
    std::vector<std::string> joint_names_;
    double kp_;
public:
    RobotController(
        const std::string & robot_name,
        const std::vector<std::string> & joint_names,
        double kp)
        : robot_name_(robot_name),
          joint_names_(joint_names),
          kp_(kp)
    {

    }

    void printJointPositions(
        const std::vector<double> & joint_positions) const
    {
        if (joint_positions.size() != joint_names_.size())
        {
            std::cout << "Error: joint position size mismatch." << std::endl;
            return;
        }

        std::cout << "Robot name: " << robot_name_ << std::endl;

        for (size_t i = 0; i < joint_names_.size(); i++)
        {
            std::cout << joint_names_[i]
                      << " position: "
                      << joint_positions[i]
                      << " rad" << std::endl;
        }
    }

    std::vector<double> computeCommands(
        const std::vector<double> & target_positions,
        const std::vector<double> & current_positions) const
    {
        std::vector<double> commands(joint_names_.size(), 0.0);

        if (target_positions.size() != joint_names_.size() ||
            current_positions.size() != joint_names_.size())
        {
            std::cout << "Error: vector size mismatch." << std::endl;
            return commands;
        }

        for (size_t i = 0; i < joint_names_.size(); i++)
        {
            double error = target_positions[i] - current_positions[i];
            commands[i] = kp_ * error;
        }
        
        return commands;
    }

     void controlLoop()
    {
        std::cout << "Control loop callback running..." << std::endl;
    }
};

int main()
{
    std::vector<std::string> joint_names = {
        "joint1",
        "joint2",
        "joint3",
        "joint4",
        "joint5",
        "joint6"
    };

     std::vector<double> current_positions = {
        0.0,
        -0.5,
        1.2,
        -1.0,
        0.8,
        0.2
    };

    std::vector<double> target_positions = {
        0.0,
        -0.7,
        1.0,
        -1.2,
        0.5,
        0.0
    };

    auto controller =
        std::make_shared<RobotController>(
            "TM14S-M",
            joint_names,
            6.0
        );

    controller->printJointPositions(current_positions);

    std::vector<double> commands =
        controller->computeCommands(
            target_positions,
            current_positions
        );

    std::cout << "Computed commands:" << std::endl;

    for (size_t i = 0; i < commands.size(); ++i)
    {
        std::cout << joint_names[i]
                  << " command: "
                  << commands[i]
                  << std::endl;
    }

    auto lambda_callback = [controller]()
    {
        controller->controlLoop();
    };

    auto bind_callback = std::bind(
        &RobotController::controlLoop,
        controller
    );

    std::cout << "Running lambda callback:" << std::endl;
    lambda_callback();

    std::cout << "Running bind callback:" << std::endl;
    bind_callback();

    std::cout << "Simulated timed loop:" << std::endl;

    for (int step = 0; step < 3; ++step)
    {
        controller->controlLoop();

        std::this_thread::sleep_for(
            std::chrono::milliseconds(500)
        );
    }

    return 0;
}