cmake_minimum_required(VERSION 3.10) # Minimum CMake version

project(robot_controller_demo) # This sets the project name

# C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create an executable named robot_demo. Build it from these source files:
add_executable(robot_demo
    src/main.cpp
    src/robot_controller.cpp)

# Include directory    
target_include_directories(robot_demo
                PRIVATE
                include)   

# Create an executable named robot_test. 
add_executable(robot_test
    src/test_robot_controller.cpp
    src/robot_controller.cpp
)

target_include_directories(robot_test
    PRIVATE
    include
)

# -----

add_library(robot_controller_lib
    src/robot_controller.cpp)

target_include_directories(robot_controller_lib
    PUBLIC
    include)

add_executable(robot_demo2
    src/test_robot_controller.cpp)

target_link_libraries(robot_demo2
    PRIVATE
    robot_controller_lib)

# ---

add_executable(multi_joint_robot_demo
    src/multi_joint_controller.cpp)

target_link_libraries(multi_joint_robot_demo
    PRIVATE
    robot_controller_lib)