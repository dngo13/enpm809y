# cmake_minimum_required(VERSION 3.10)
project(Final-Project-Group3)

set(CMAKE_CXX_STANDARD 14)

add_executable(Final-Project-Group3
        main.cpp src/LandBasedRobot/LandBasedRobot.cpp src/LandBasedRobot/LandBasedRobot.h src/LandBasedWheeled/landbasedwheeled.cpp
        src/LandBasedWheeled/landbasedwheeled.h src/LandBasedTracked/landbasedtracked.cpp src/LandBasedTracked/landbasedtracked.h )
