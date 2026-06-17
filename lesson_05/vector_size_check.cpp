#include <cmath>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> joint_names = {
        "joint1",
        "joint2",
        "joint3",
        "joint4"
    };

    std::vector<double> target_positions = {
        0.0,
        -1.0,
        0.7
    };

    if (joint_names.size() != target_positions.size())
    {
        std::cout << "Error: vector size mismatch!" << std::endl;
        std::cout << "joint_name size: " << joint_names.size() << std::endl;
        std::cout << "target_positions size: " << target_positions.size() << std::endl;
        return 1;
    }

    for ( size_t i = 0; i < joint_names.size(); i++)
    {
        std::cout << joint_names[i]
                  << " | target: " << target_positions[i]
                  << std::endl;
    }

    return 0;
}