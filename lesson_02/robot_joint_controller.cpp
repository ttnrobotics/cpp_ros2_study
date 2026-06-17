#include <iostream>
#include <string>

using namespace std;

int main() {
    string robot_name = "TM14S-M";
    string joint_name = "joint1";

    double target_position = 0.01;
    double current_position = 0.03;

    double kp = 5.0;

    bool robot_enabled = true;
    cout << boolalpha; // Enable boolean output as true/false

    double position_error = target_position - current_position;

    double command = kp * position_error;

    cout << "Robot name: " << robot_name << endl;
    cout << "Joint name: " << joint_name << endl;
    cout << "Target position: " << target_position << " rad" << endl;
    cout << "Current position: " << current_position << " rad" << endl;
    cout << "Position error: " << position_error << " rad" << endl;
    cout << "P controller command: " << command << endl;
    cout << "Robot enabled: " << robot_enabled << endl;

    return 0;
}