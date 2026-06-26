#include <iostream>
#include <string>
#include <vector>

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

    std::vector<double> joint_positions = {
        0.0,
        -0.5,
        1.2,
        -1.0,
        0.8,
        0.2
    };

    if (joint_names.size() != joint_positions.size())
    {
        std::cout << "Error: vector size mismatch." << std::endl;
        return 1;
    }

    for (size_t i = 0; i < joint_names.size(); i++)
    {
        std::cout << joint_names[i]
                  << " position: "
                  << joint_positions[i] << " rad"
                  << std::endl;
    }

    return 0;
}