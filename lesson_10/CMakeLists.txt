cmake_minimum_required(VERSION 3.10)

project(robot_controller_demo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(robot_demo
    src/main.cpp
    src/robot_controller.cpp)

target_include_directories(robot_demo
                PRIVATE
                include)   