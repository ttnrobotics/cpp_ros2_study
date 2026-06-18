#include<iostream>
#include<string>

void printRobotInfo(const std::string & robot_name, int number_of_joints)
{
    std::cout << "Robot name: " << robot_name << std::endl;
    std::cout << "Number of joints: " << number_of_joints << std::endl;
}

int main()
{
    std::string robot_name = "Cobot";

    int number_of_joints = 6;

    printRobotInfo(robot_name, number_of_joints);

    return 0;
}