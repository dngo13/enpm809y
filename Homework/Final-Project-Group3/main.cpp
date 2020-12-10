
#include "src/LandBasedWheeled/landbasedwheeled.h"
#include "src/LandBasedTracked/landbasedtracked.h"
#include <iostream>
#include <string>
#include "src/API/api.h"
#include "src/Maze/Maze.h"
#include "src/Algorithm/Algorithm.h"

//For simulator
//g++ ../main.cpp API/api.cpp LandBasedRobot/LandBasedRobot.cpp LandBasedTracked/landbasedtracked.cpp LandBasedWheeled/landbasedwheeled.cpp Algorithm/Algorithm.cpp

int main(){


    std::shared_ptr<fp::LandBasedRobot> wheeled = std::make_shared<fp::LandBasedWheeled>("Husky", 0, 0, 'N');
    fp::Algorithm algorithm;
    algorithm.Solve();

    return 0;
}