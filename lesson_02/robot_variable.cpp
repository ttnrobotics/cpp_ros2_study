#include <iostream>
#include <string>

using namespace std;

int main(){
    string robot_name = "TM14S-M";
    int number_of_joints = 6;

    double joint1_position = 0.0;
    double joint2_position = -1.0;
    double joint3_position = 0.7;
    double joint4_position = 0.3;
    double joint5_position = 0.8;
    double joint6_position = 0.2;

    bool robot_enabled = true;
    
    cout << boolalpha; // Enable boolean output as true/false

    cout << "Robot name: " << robot_name << endl;
    cout << "Number of joints: " << number_of_joints << endl;
    cout << "Joint 1 position: " << joint1_position << "rad" << endl;
    cout << "Joint 2 position: " << joint2_position << "rad" << endl;
    cout << "Joint 3 position: " << joint3_position << "rad" << endl;
    cout << "Joint 4 position: " << joint4_position << "rad" << endl;
    
    
    cout << "Robot enabled: " << robot_enabled << endl;

    return 0;
}