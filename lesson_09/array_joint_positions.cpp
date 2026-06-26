#include <array>
#include <iostream>

int main()
{
    std::array<double, 6> joint_positions = {
        0.0,
        -0.5,
        1.2,
        -1.0,
        0.8,
        0.2
    };

    std::string joint_names[6] = {
        "joint1",
        "joint2",
        "joint3",
        "joint4",
        "joint5",
        "joint6"
    };

    for (size_t i = 0; i < joint_positions.size(); ++i)
    {
        std::cout << joint_names[i]
                  << " position: "
                  << joint_positions[i]
                  << " rad"
                  << std::endl;
    }

    return 0;
}