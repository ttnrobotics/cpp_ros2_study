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

    std::cout << "Number of joints: " << joint_names.size() << std::endl;

    for (size_t i = 0; i < joint_names.size(); ++i)
    {
        std::cout << "Joint index" << i
                  << " name: " << joint_names[i]
                  << std::endl;
    }

    return 0;
}