#include <iostream>
#include <string>

int main() {
    std::string joint_name = "joint1";

    double target_position = 3.2;

    double min_limit = -2.9;
    double max_limit = 2.9;

    std::cout << "Joint Name: " << joint_name << std::endl;
    std::cout << "Target Position: " << target_position << " rad" << std::endl;
    std::cout << "Minimun limit: " << min_limit << " rad" << std::endl;
    std::cout << "Maximum limit: " << max_limit << " rad" << std::endl;

    if (target_position >= min_limit && target_position <= max_limit){
        std::cout << "Target position is inside joint limit!" << std::endl;
        std::cout << "Command is safe." << std::endl;
    } else {
        std::cout << "Target is out of joint limit!" << std::endl;
        std::cout << "Command is rejected." << std::endl;
    }

    
    return 0;
}