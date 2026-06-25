#include <iostream>

int main()
{
    double joint_position = 1.57;
    double * position_pt = &joint_position;

    std::cout << "Joint position: " << joint_position << std::endl;
    std::cout << "Address of joint_position: " << &joint_position << std::endl;
    std::cout << "Pointer stores address: " << position_pt << std::endl;
    std::cout << "Value through pointer: " << *position_pt << std::endl;

    return 0;

}