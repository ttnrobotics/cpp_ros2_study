#include<iostream>
#include<string>

bool isInsideLimit(double target, double min_limit, double max_limit)
{
    return target >= min_limit && target <= max_limit;
}

int main()
{
    std::string joint_name = "joint1";

    double target_position = 1.0;
    double min_limit = -2.9;
    double max_limit = 2.9;

    bool target_safe = isInsideLimit(target_position, min_limit, max_limit);
    std::cout << std::boolalpha;

    std::cout << "Joint name: " << joint_name << std::endl;
    std::cout << "Target position: " << target_position << std::endl;
    std::cout << "Minimum limit: " << min_limit << std::endl;
    std::cout << "Maximum limit: " << max_limit << std::endl;
    std::cout << "Target safe: " << target_safe << std::endl;

    if(target_safe)
    {
        std::cout << "Command accepted." << std::endl;
    }
    else
    {
        std::cout << "Command rejected." << std::endl;
    }

    return 0;
}