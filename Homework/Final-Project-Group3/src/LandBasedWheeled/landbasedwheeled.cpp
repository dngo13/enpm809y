#include "landbasedwheeled.h"
#include <iostream>
#include "../API/api.h"


void fp::LandBasedWheeled::MoveForward(int x, int y, char direction) {
    fp::Algorithm::log("LandBasedWheeled::MoveForward is called");
    fp::API::moveForward();
}
void fp::LandBasedWheeled::TurnLeft() {
    fp::Algorithm::log("LandBasedWheeled::TurnLeft is called");
    fp::API::turnLeft();
}

void fp::LandBasedWheeled::TurnRight() {
    fp::Algorithm::log("LandBasedTracked::TurnRight is called");
    fp::API::turnRight();
}

char fp::LandBasedWheeled::GetDirection() {
    fp::Algorithm::log("LandBasedWheeled::GetDirection is called");
    return direction_;
}
