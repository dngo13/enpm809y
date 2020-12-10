#include "LandBasedRobot.h"
#include <iostream>

namespace fp {
    void fp::LandBasedRobot::GoUp(int x, int y) {
        std::cout << "LandBasedRobot::GoUp is called\n";
    }

    void fp::LandBasedRobot::GoDown(int x, int y) {
        std::cout << "LandBasedRobot::GoDown is called\n";
    }

    void fp::LandBasedRobot::TurnLeft(int x, int y) {
        std::cout << "LandBasedRobot::TurnLeft is called\n";
    }

    void fp::LandBasedRobot::TurnRight(int x, int y) {
        std::cout << "LandBasedRobot::TurnRight is called\n";
    }

     void LandBasedRobot::PickUp(std::string obj) {
        std::cout << "LandBasedRobot::PickUp is called\n";
    }

    void fp::LandBasedRobot::Release(std::string obj) {
        std::cout << "LandBasedRobot::Release is called\n";
    }

}//--namespace fp