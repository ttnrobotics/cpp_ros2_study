# Lesson 2 — Variables and Data Types for Robot States

Owner: ttn

## 1. Goal

In this lesson, you will learn how to store robot information using C++ variables.

You will study:

```cpp
int
double
bool
std::string
```

These are very important because robot programs always need to store data such as:

```
joint position
joint velocity
joint torque
robot name
robot state
control mode
error value
```

---

# 2. Why Variables Are Important in ROS 2

In ROS 2, robot data usually comes from topics.

For example, `/joint_states` contains:

```
joint names
joint positions
joint velocities
joint efforts/torques
```

Later in ROS 2 C++, you will see something like this:

```cpp
double joint_position = msg->position[0];
double joint_velocity = msg->velocity[0];
double joint_effort   = msg->effort[0];
```

So before learning ROS 2 messages, you must clearly understand variables.

---

# 3. What Is a Variable?

A variable is a box that stores data.

Example:

```cpp
double joint1_position = 1.57;
```

Meaning:

```
Create a variable named joint1_position.
Its type is double.
Its value is 1.57.
```

In robotics, `1.57` usually means radians.

```
1.57 rad ≈ 90 degrees
```

---

# 4. Common C++ Data Types for Robotics

| Type | Example | Meaning |
| --- | --- | --- |
| `int` | `int number_of_joints = 6;` | integer number |
| `double` | `double position = 1.57;` | decimal number |
| `bool` | `bool robot_enabled = true;` | true / false |
| `std::string` | `std::string robot_name = "TM14S";` | text |

---

# 5. First Example: Robot Variables

Create today’s lesson folder:

```bash
mkdir -p ~/cpp_ros2_study/lesson_02
cd ~/cpp_ros2_study/lesson_02
```

Create a file:

```bash
code robot_variables.cpp
```

Or:

```bash
nano robot_variables.cpp
```

Write this code:

```cpp
#include <iostream>
#include <string>

int main()
{
    std::string robot_name = "OpenManipulator-X";
    int number_of_joints = 4;

    double joint1_position = 0.0;
    double joint2_position = -1.0;
    double joint3_position = 0.7;
    double joint4_position = 0.3;

    bool robot_enabled = true;

    std::cout << "Robot name: " << robot_name << std::endl;
    std::cout << "Number of joints: " << number_of_joints << std::endl;

    std::cout << "Joint 1 position: " << joint1_position << " rad" << std::endl;
    std::cout << "Joint 2 position: " << joint2_position << " rad" << std::endl;
    std::cout << "Joint 3 position: " << joint3_position << " rad" << std::endl;
    std::cout << "Joint 4 position: " << joint4_position << " rad" << std::endl;

    std::cout << "Robot enabled: " << robot_enabled << std::endl;

    return 0;
}
```

Compile:

```bash
g++ robot_variables.cpp -o robot_variables
```

Run:

```bash
./robot_variables
```

Expected output:

```
Robot name: OpenManipulator-X
Number of joints: 4
Joint 1 position: 0 rad
Joint 2 position: -1 rad
Joint 3 position: 0.7 rad
Joint 4 position: 0.3 rad
Robot enabled: 1
```

Important:

```
true  prints as 1
false prints as 0
```

---

# 6. Line-by-Line Explanation

## Include libraries

```cpp
#include <iostream>
#include <string>
```

`iostream` is used for printing.

`string` is used for text variables.

---

## Robot name

```cpp
std::string robot_name = "OpenManipulator-X";
```

This stores text.

In robotics, you can use `std::string` for:

```
robot name
joint name
topic name
frame name
control mode
```

Examples:

```cpp
std::string joint_name = "joint1";
std::string topic_name = "/joint_states";
std::string control_mode = "position_control";
```

---

## Number of joints

```cpp
int number_of_joints = 4;
```

`int` stores whole numbers.

Use `int` for:

```
number of joints
counter
index
loop count
state number
```

Examples:

```cpp
int number_of_joints = 6;
int control_frequency = 100;
int current_step = 0;
```

---

## Joint positions

```cpp
double joint1_position = 0.0;
```

`double` stores decimal numbers.

Use `double` for most robot math:

```
position
velocity
acceleration
torque
force
error
time
gain
```

Examples:

```cpp
double position = 1.57;
double velocity = 0.2;
double torque = 3.5;
double error = 0.01;
double kp = 10.0;
```

In robot control, most numerical values should be `double`.

---

## Robot enabled state

```cpp
bool robot_enabled = true;
```

`bool` stores only two values:

```
true
false
```

Use `bool` for robot state checking:

```cpp
bool robot_enabled = true;
bool emergency_stop = false;
bool target_reached = false;
bool gripper_closed = true;
bool has_error = false;
```

---

# 7. Better Boolean Printing

Instead of printing:

```
Robot enabled: 1
```

you can print:

```
Robot enabled: true
```

Modify this line:

```cpp
std::cout << "Robot enabled: " << robot_enabled << std::endl;
```

to:

```cpp
std::cout << std::boolalpha;
std::cout << "Robot enabled: " << robot_enabled << std::endl;
```

Full improved code:

```cpp
#include <iostream>
#include <string>

int main()
{
    std::string robot_name = "OpenManipulator-X";
    int number_of_joints = 4;

    double joint1_position = 0.0;
    double joint2_position = -1.0;
    double joint3_position = 0.7;
    double joint4_position = 0.3;

    bool robot_enabled = true;

    std::cout << std::boolalpha;

    std::cout << "Robot name: " << robot_name << std::endl;
    std::cout << "Number of joints: " << number_of_joints << std::endl;

    std::cout << "Joint 1 position: " << joint1_position << " rad" << std::endl;
    std::cout << "Joint 2 position: " << joint2_position << " rad" << std::endl;
    std::cout << "Joint 3 position: " << joint3_position << " rad" << std::endl;
    std::cout << "Joint 4 position: " << joint4_position << " rad" << std::endl;

    std::cout << "Robot enabled: " << robot_enabled << std::endl;

    return 0;
}
```

Compile and run again:

```bash
g++ robot_variables.cpp -o robot_variables
./robot_variables
```

Expected output:

```
Robot name: OpenManipulator-X
Number of joints: 4
Joint 1 position: 0 rad
Joint 2 position: -1 rad
Joint 3 position: 0.7 rad
Joint 4 position: 0.3 rad
Robot enabled: true
```

---

# 8. Robotics Example: Target, Current, Error

In robot control, the most important idea is:

```
error = target - current
```

Example:

```cpp
double target_position = 1.0;
double current_position = 0.7;
double position_error = target_position - current_position;
```

The error is:

```
1.0 - 0.7 = 0.3 rad
```

That means the joint still needs to move by `0.3 rad`.

---

# 9. Second Program: Joint Error

Create another file:

```bash
code joint_error.cpp
```

Write:

```cpp
#include <iostream>
#include <string>

int main()
{
    std::string joint_name = "joint1";

    double target_position = 1.0;
    double current_position = 0.7;

    double position_error = target_position - current_position;

    std::cout << "Joint name: " << joint_name << std::endl;
    std::cout << "Target position: " << target_position << " rad" << std::endl;
    std::cout << "Current position: " << current_position << " rad" << std::endl;
    std::cout << "Position error: " << position_error << " rad" << std::endl;

    return 0;
}
```

Compile:

```bash
g++ joint_error.cpp -o joint_error
```

Run:

```bash
./joint_error
```

Expected output:

```
Joint name: joint1
Target position: 1 rad
Current position: 0.7 rad
Position error: 0.3 rad
```

This is already a small robot control concept.

Later, this becomes:

```cpp
error = desired_joint_position - measured_joint_position;
command = kp * error;
```

That is the beginning of PID control.

---

# 10. Third Program: Simple P Controller

Now we make a very simple controller.

Control law:

```
command = kp × error
```

Create file:

```bash
code simple_p_controller.cpp
```

Write:

```cpp
#include <iostream>
#include <string>

int main()
{
    std::string joint_name = "joint1";

    double target_position = 1.0;
    double current_position = 0.7;

    double kp = 10.0;

    double position_error = target_position - current_position;
    double command = kp * position_error;

    std::cout << "Joint name: " << joint_name << std::endl;
    std::cout << "Target position: " << target_position << " rad" << std::endl;
    std::cout << "Current position: " << current_position << " rad" << std::endl;
    std::cout << "Position error: " << position_error << " rad" << std::endl;
    std::cout << "Kp gain: " << kp << std::endl;
    std::cout << "Control command: " << command << std::endl;

    return 0;
}
```

Compile:

```bash
g++ simple_p_controller.cpp -o simple_p_controller
```

Run:

```bash
./simple_p_controller
```

Expected output:

```
Joint name: joint1
Target position: 1 rad
Current position: 0.7 rad
Position error: 0.3 rad
Kp gain: 10
Control command: 3
```

Meaning:

```
The error is 0.3.
The gain is 10.
The command is 3.
```

In a real robot, this command could become:

```
motor position command
velocity command
torque command
PWM command
current command
```

depending on the controller design.

---

# 11. Important Rule: Use Good Variable Names

Bad:

```cpp
double a = 1.0;
double b = 0.7;
double c = a - b;
```

This works, but it is hard to understand.

Good:

```cpp
double target_position = 1.0;
double current_position = 0.7;
double position_error = target_position - current_position;
```

This is much better for robotics code.

Use names that explain the meaning.

Good robot variable names:

```cpp
double target_joint_position;
double current_joint_position;
double joint_velocity;
double joint_torque;
double position_error;
double velocity_error;
double control_command;
bool robot_enabled;
bool emergency_stop;
std::string robot_name;
```

---

# 12. Common Errors

## Error 1 — Missing semicolon

Wrong:

```cpp
double position = 1.0
```

Correct:

```cpp
double position = 1.0;
```

---

## Error 2 — String without include

Wrong:

```cpp
#include <iostream>

int main()
{
    std::string robot_name = "TM14S";
}
```

This may cause an error because you forgot:

```cpp
#include <string>
```

Correct:

```cpp
#include <iostream>
#include <string>
```

---

## Error 3 — Text without quotation marks

Wrong:

```cpp
std::string robot_name = TM14S;
```

Correct:

```cpp
std::string robot_name = "TM14S";
```

Text must be inside double quotation marks.

---

## Error 4 — Using comma instead of dot

Wrong:

```cpp
double position = 1,57;
```

Correct:

```cpp
double position = 1.57;
```

C++ uses `.` for decimal numbers.

---

# 13. Practice Tasks

## Practice 1 — Change Robot Information

In `robot_variables.cpp`, change the robot to TM14S:

```
Robot name: TM14S-M
Number of joints: 6
Joint 1 position: 0.0
Joint 2 position: -0.5
Joint 3 position: 1.2
Joint 4 position: -1.0
Joint 5 position: 0.8
Joint 6 position: 0.2
Robot enabled: true
```

You need to add two more joint variables:

```cpp
double joint5_position = 0.8;
double joint6_position = 0.2;
```

---

## Practice 2 — Compute Error for Joint 2

Create:

```bash
code joint2_error.cpp
```

Use:

```cpp
double target_position = -1.2;
double current_position = -0.8;
```

Compute:

```cpp
double position_error = target_position - current_position;
```

Expected error:

```
-0.4 rad
```

Because:

```
-1.2 - (-0.8) = -0.4
```

---

## Practice 3 — Simple P Controller for Gripper

Create:

```bash
code gripper_p_controller.cpp
```

Use:

```cpp
std::string joint_name = "gripper";
double target_position = 0.01;
double current_position = 0.03;
double kp = 5.0;
```

Compute:

```cpp
double error = target_position - current_position;
double command = kp * error;
```

Expected:

```
error = -0.02
command = -0.1
```

Meaning:

The gripper needs to close more.

---

# 14. Small Quiz

## Question 1

Which type should you use for joint position?

A. `int`

B. `double`

C. `bool`

D. `char`

Answer: **B. `double`**

---

## Question 2

Which type should you use for robot name?

A. `double`

B. `int`

C. `std::string`

D. `bool`

Answer: **C. `std::string`**

---

## Question 3

Which type should you use for emergency stop state?

A. `double`

B. `bool`

C. `std::string`

D. `int`

Answer: **B. `bool`**

---

## Question 4

What is the result?

```cpp
double target = 1.0;
double current = 0.6;
double error = target - current;
```

Answer:

```
0.4
```

---

## Question 5

What is the result?

```cpp
double target = -1.0;
double current = -0.4;
double error = target - current;
```

Answer:

```
-0.6
```

Because:

```
-1.0 - (-0.4) = -0.6
```

---

# 15. Mini Assignment

Create a file:

```bash
robot_joint_controller.cpp
```

Write a C++ program that stores:

```
robot name
joint name
target position
current position
position error
Kp gain
control command
robot enabled state
```

Use these values:

```cpp
std::string robot_name = "OpenManipulator-X";
std::string joint_name = "joint2";

double target_position = -1.2;
double current_position = -0.9;
double kp = 8.0;

bool robot_enabled = true;
```

Compute:

```cpp
double position_error = target_position - current_position;
double control_command = kp * position_error;
```

Expected output should look like:

```
Robot name: OpenManipulator-X
Joint name: joint2
Target position: -1.2 rad
Current position: -0.9 rad
Position error: -0.3 rad
Kp gain: 8
Control command: -2.4
Robot enabled: true
```

Compile:

```bash
g++ robot_joint_controller.cpp -o robot_joint_controller
./robot_joint_controller
```

---

# 16. What You Must Understand Before Lesson 3

Before moving to the next lesson, you should understand:

```
1. What is a variable?
2. What is int?
3. What is double?
4. What is bool?
5. What is std::string?
6. Why do we use double for joint positions?
7. How to compute position error?
8. How to compute a simple P control command?
```