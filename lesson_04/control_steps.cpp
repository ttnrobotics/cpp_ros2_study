#include <iostream>
#include <string>

int main() {
    std::string robot_name = "Cobot";
    int number_of_steps = 10;

    std::cout << "Robot Name: " << robot_name << std::endl;
    std::cout << "Starting control loop..." << std::endl;

    for (int step =0; step < number_of_steps; ++step){
        std::cout << "Control step: " << step << ":";
        std::cout << "reading sensor, computing command, sending command" << std::endl;
    }

    std::cout << "Control loop finished." << std::endl;

    return 0;
}