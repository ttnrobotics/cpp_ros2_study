#include<iostream>

int main()
{
    const double pi = 3.141592;
    const double max_joint_limit = 2.9;

    double target_position = 1.0;

    std::cout << "pi: " << pi << std::endl;
    std::cout << "Maximum joint limit: " << max_joint_limit << std::endl;
    std::cout << "Target position: " << target_position << std::endl;

    return 0;
}