# cmake_minimum_required(VERSION <specify CMake version here>)
project(rwa3_ngo)

set(CMAKE_CXX_STANDARD 14)

add_executable(rwa3_group3
        main.cpp LandBasedRobot/LandBasedRobot.cpp LandBasedRobot/LandBasedRobot.h LandBasedWheeled/landbasedwheeled.cpp LandBasedWheeled/landbasedwheeled.h LandBasedTracked/landbasedtracked.cpp LandBasedTracked/landbasedtracked.h )
