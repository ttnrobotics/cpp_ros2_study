#include<iostream>
#include<string>
#include<vector>

void printJointPosition(
    const std::vector<std::string> & joint_names,
    const std::vector<double> & joint_positions)
{
    if (joint_names.size() != joint_positions.size())
    {
        std::cout << "Error: vector size mismatch." << std::endl;
        return;
    }

    for (size_t i = 0; i < joint_names.size(); ++i)
    {
        std::cout << joint_names[i]
                  << " position: "
                  << joint_positions[i]
                  << " rad" << std::endl;
    }
}

int main()
{
    std::vector<std::string> joint_names = {
        "joint1",
        "joint2",
        "joint3",
        "joint4"
    };

    std::vector<double> joint_positions = {
        0.0,
        -1.0,
        0.7,
        0.3
    };

    printJointPosition(joint_names, joint_positions);

    return 0;
}