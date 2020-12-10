#include "LandBasedRobot.h"
#include <iostream>
#include "../API/api.h"

namespace fp {
    char fp::LandBasedRobot::GetDirection() {
        return direction_;
    }
    void fp::LandBasedRobot::MoveForward(int x, int y, char direction) {
        std::cout << "LandBasedRobot::MoveForward is called\n";
        fp::API::moveForward();
    }
    void fp::LandBasedRobot::TurnLeft() {
        std::cout << "LandBasedRobot::TurnLeft is called\n";
        fp::API::turnLeft();
    }

    void fp::LandBasedRobot::TurnRight() {
        std::cout << "LandBasedRobot::TurnRight is called\n";
        fp::API::turnRight();
    }


}//--namespace fp