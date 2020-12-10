# cmake_minimum_required(VERSION 3.10)
project(Final-Project-Group3)

set(CMAKE_CXX_STANDARD 14)

add_executable(Final-Project-Group3
        main.cpp src/API/api.h src/API/api.cpp  src/LandBasedRobot/LandBasedRobot.cpp src/LandBasedRobot/LandBasedRobot.h src/LandBasedWheeled/landbasedwheeled.cpp
        src/LandBasedWheeled/landbasedwheeled.h src/LandBasedTracked/landbasedtracked.cpp src/LandBasedTracked/landbasedtracked.h
        src/Maze/Maze.h src/Maze/Maze.cpp src/Algorithm/Algorithm.h src/Algorithm/Algorithm.cpp)
