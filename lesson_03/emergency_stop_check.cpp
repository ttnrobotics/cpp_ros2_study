#include <iostream>
#include <string>

int main() {
    std::string robot_name = "TM14S-M";
    
    bool robot_enabled = true;
    bool emergency_stop = true;

    std::cout << std::boolalpha; // Print bool values as true/false

    std::cout << "Robot Name: " << robot_name << std::endl;
    std::cout << "Robot Enabled: " << robot_enabled <<std::endl;
    std::cout << "Emergency Stop: " << emergency_stop << std::endl;

    if (emergency_stop) {
        std::cout << "EMERGENCY STOP ACTIVE!" << std::endl;
        std::cout << "Robot motion is blocked." << std::endl;
    } else {
        std::cout << "Emergency stop is not active." << std::endl;
    }

    return 0;
}