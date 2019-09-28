cmake_minimum_required(VERSION 3.5)

set (CMAKE_CXX_STANDARD 14)

add_library(robot
    src/robot.cpp
    )

add_library(sensor INTERFACE)
target_include_directories(sensor INTERFACE include/sensor.h)

add_subdirectory(specs)
