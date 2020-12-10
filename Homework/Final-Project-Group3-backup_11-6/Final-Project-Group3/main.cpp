
#include "src/LandBasedWheeled/landbasedwheeled.h"
#include "src/LandBasedTracked/landbasedtracked.h"
#include <iostream>
#include <string>
#include "src/API/api.h"
#include "src/Maze/Maze.h"
#include "src/Algorithm/Algorithm.h"
/**
 * To create the maze class you can create a 16x16 2D array
 * as you move your robot in the environment and find new walls
 * you can update this maze
 * In the slides wall between 2 sides
 */

//For simulator
//g++ ../main.cpp API/api.cpp LandBasedRobot/LandBasedRobot.cpp LandBasedTracked/landbasedtracked.cpp LandBasedWheeled/landbasedwheeled.cpp Algorithm/Algorithm.cpp

int main(){
    std::shared_ptr<fp::LandBasedRobot> wheeled = std::make_shared<fp::LandBasedWheeled>("Husky", 0, 0, 'N');
    fp::Algorithm algorithm;
    algorithm.Solve();

    return 0;
}