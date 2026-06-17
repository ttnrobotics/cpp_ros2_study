#include <iostream>
#include <string>

int main() {
    std::string robot_name = "TM14S-M";
    
    bool robot_enabled = true;
    bool emergency_stop = false;
    bool robot_error = false;

    std::cout << std::boolalpha; // Print bool values as true/false

    std::cout << "Robot Name: " << robot_name << std::endl;
    std::cout << "Robot Enabled: " << robot_enabled <<std::endl;
    std::cout << "Emergency Stop: " << emergency_stop << std::endl;
    std::cout << "Robot Error: " << robot_error << std::endl;


    if (robot_enabled && ! emergency_stop && !robot_error) {
        std::cout << "Motion allowed." << std::endl;
    } else {
        std::cout << "Motion blocked." << std::endl;
    }

    return 0;
}