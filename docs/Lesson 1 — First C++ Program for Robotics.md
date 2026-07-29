# Lesson 1 — First C++ Program for Robotics

Owner: ttn

## 1. Goal

In this lesson, you will learn:

```
- basic C++ program structure
- #include
- main function
- std::cout
- compile with g++
- run a C++ program
```

This is the first step before ROS 2 C++.

---

## 2. Why This Is Important in ROS 2

Every ROS 2 C++ node also starts from a normal C++ program.

Later, a ROS 2 node will look like this:

```cpp
int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MyNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
```

So before learning this, you must understand simple `main()` first.

---

# 3. First Program

Create a folder:

```bash
mkdir -p ~/cpp_ros2_study/lesson_01
cd ~/cpp_ros2_study/lesson_01
```

Create a file:

```bash
code hello_robot.cpp
```

Or use nano:

```bash
nano hello_robot.cpp
```

Write this code:

```cpp
#include <iostream>

int main()
{
    std::cout << "Hello, ROS 2 C++ robotics!" << std::endl;

    return 0;
}
```

Save the file.

---

# 4. Compile the Program

Run:

```bash
g++ hello_robot.cpp -o hello_robot
```

Then run:

```bash
./hello_robot
```

Expected output:

```
Hello, ROS 2 C++ robotics!
```

---

# 5. Line-by-Line Explanation

## Line 1

```cpp
#include <iostream>
```

This includes the input/output library.

You need this because you want to print text to the terminal.

---

## Line 3

```cpp
int main()
```

This is the starting point of the program.

When you run:

```bash
./hello_robot
```

the computer starts executing from `main()`.

---

## Line 5

```cpp
std::cout << "Hello, ROS 2 C++ robotics!" << std::endl;
```

This prints text to the terminal.

Meaning:

| Code | Meaning |
| --- | --- |
| `std::cout` | output to terminal |
| `<<` | send data to output |
| text inside `" "` | message |
| `std::endl` | new line |

---

## Line 7

```cpp
return 0;
```

This means the program finished successfully.

In C++, returning `0` from `main()` usually means:

```
No error
```

---

# 6. Important Concept

A C++ program usually has this shape:

```cpp
#include <library>

int main()
{
    // your code here

    return 0;
}
```

Later, your ROS 2 C++ node will also follow this basic structure.

---

# 7. Practice 1

Modify the program to print your name:

```cpp
#include <iostream>

int main()
{
    std::cout << "My name is Truong Thanh Nguyen" << std::endl;
    std::cout << "I am studying C++ for ROS 2 Humble" << std::endl;
    std::cout << "My goal is robotics control programming" << std::endl;

    return 0;
}
```

Compile again:

```bash
g++ hello_robot.cpp -o hello_robot
./hello_robot
```

Expected output:

```
My name is Truong Thanh Nguyen
I am studying C++ for ROS 2 Humble
My goal is robotics control programming
```

---

# 8. Practice 2 — Robotics Meaning

Now create another file:

```bash
code robot_info.cpp
```

Write:

```cpp
#include <iostream>

int main()
{
    std::cout << "Robot name: OpenManipulator-X" << std::endl;
    std::cout << "Number of joints: 4" << std::endl;
    std::cout << "Controller type: PID" << std::endl;
    std::cout << "Middleware: ROS 2 Humble" << std::endl;

    return 0;
}
```

Compile:

```bash
g++ robot_info.cpp -o robot_info
./robot_info
```

Expected output:

```
Robot name: OpenManipulator-X
Number of joints: 4
Controller type: PID
Middleware: ROS 2 Humble
```

---

# 9. Common Errors

## Error 1

```
fatal error: iostream: No such file or directory
```

Possible reason:

You typed:

```cpp
#include "iostream"
```

Better use:

```cpp
#include <iostream>
```

---

## Error 2

```
error: expected ';' before return
```

You forgot semicolon:

Wrong:

```cpp
std::cout << "Hello" << std::endl
```

Correct:

```cpp
std::cout << "Hello" << std::endl;
```

---

## Error 3

```
command not found: g++
```

Install compiler:

```bash
sudo apt update
sudo apt install build-essential
```

---

# 10. Small Quiz

Answer these by yourself.

## Question 1

What is the starting function of a C++ program?

A. `start()`

B. `main()`

C. `run()`

D. `begin()`

Correct answer: **B. `main()`**

---

## Question 2

What does this line do?

```cpp
#include <iostream>
```

A. Starts the robot

B. Includes input/output library

C. Creates a ROS 2 node

D. Runs the compiler

Correct answer: **B. Includes input/output library**

---

## Question 3

What does `std::cout` do?

A. Reads keyboard input

B. Prints output to terminal

C. Compiles the program

D. Creates a variable

Correct answer: **B. Prints output to terminal**

---

# 11. Mini Assignment

Create a file:

```bash
robot_profile.cpp
```

Write a program that prints:

```
Robot name
Robot type
Number of joints
Control method
ROS version
Your study goal
```

Example output:

```
Robot name: TM14S-M
Robot type: Collaborative robot
Number of joints: 6
Control method: ROS 2 + TM driver
ROS version: Humble
Study goal: Learn C++ for robot control
```

Compile it:

```bash
g++ robot_profile.cpp -o robot_profile
./robot_profile
```

---

# 12. What You Should Understand Before Moving On

Before going to Lesson 2, you should be able to explain:

```
1. What is #include?
2. What is main()?
3. What is std::cout?
4. Why do we write return 0?
5. How to compile using g++?
6. How to run the compiled program?
```