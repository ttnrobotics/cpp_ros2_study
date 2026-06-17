#include <iostream>
#include <string>


int main() {
    int robot_state = 1;

    if (robot_state == 0) {
        std::cout << "Robot state: IDLE" << std::endl;
    } else if (robot_state == 1) {
        std::cout << "Robot state: MOVING" << std::endl;
    } else if (robot_state == 2) {
        std::cout << "Robot state: ERROR" << std::endl;
    } else {
        std::cout << "Robot state: UNKNOWN" << std::endl;
    }
    
    return 0;
}