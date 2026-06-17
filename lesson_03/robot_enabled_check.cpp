#include <iostream>
#include <string>

int main() {
    std::string robot_name = "Cobot";
    bool robot_enabled = false;

    std::cout << std::boolalpha; // Print bool values as true/false

    std::cout << "Robot Name: " << robot_name << std::endl;
    std::cout << "Robot Enabled: " << robot_enabled <<std::endl;

    if (robot_enabled){
        std::cout << "Robot is ready to move." << std::endl;
    } else {
        std::cout << "Robot is disabled. Motion is not allowed." << std::endl;
    }

    return 0;
}