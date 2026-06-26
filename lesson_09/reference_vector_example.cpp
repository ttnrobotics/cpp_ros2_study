#include <iostream>
#include <vector>

void printJointPositions(const std::vector<double> & joint_positions)
{
    for (size_t i = 0; i < joint_positions.size(); ++i)
    {
        std::cout << "joint" << i + 1
                  << " position: "
                  << joint_positions[i]
                  << " rad"
                  << std::endl;
    }
}

int main()
{
    std::vector<double> joint_positions = {
        0.0,
        -0.5,
        1.2,
        -1.0,
        0.8,
        0.2
    };

    printJointPositions(joint_positions);

    return 0;
}