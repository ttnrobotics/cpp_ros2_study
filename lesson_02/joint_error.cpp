#include <iostream>
#include <string>

using namespace std;

int main() {
    string joint_name = "joint1";

    double target_position = 1.0;
    double current_position = 0.7;

    double position_error = target_position - current_position;

    cout << "Joint name: " << joint_name << endl;
    cout << "Target position: " << target_position << " rad" << endl;
    cout << "Current position: " << current_position << " rad" << endl;
    cout << "Position error: " << position_error << " rad" << endl;

    return 0;
}