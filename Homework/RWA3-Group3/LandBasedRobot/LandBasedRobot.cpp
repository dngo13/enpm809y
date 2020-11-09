#include "LandBasedRobot.h"
#include <iostream>

namespace rwa3 {
    void rwa3::LandBasedRobot::GoUp(int x, int y) {
        std::cout << "LandBasedRobot::GoUp is called\n";
    }

    void rwa3::LandBasedRobot::GoDown(int x, int y) {
        std::cout << "LandBasedRobot::GoDown is called\n";
    }

    void rwa3::LandBasedRobot::TurnLeft(int x, int y) {
        std::cout << "LandBasedRobot::TurnLeft is called\n";
    }

    void rwa3::LandBasedRobot::TurnRight(int x, int y) {
        std::cout << "LandBasedRobot::TurnRight is called\n";
    }

     void LandBasedRobot::PickUp(std::string obj) {
        std::cout << "LandBasedRobot::PickUp is called\n";
    }

    void rwa3::LandBasedRobot::Release(std::string obj) {
        std::cout << "LandBasedRobot::Release is called\n";
    }

}//--namespace rwa3