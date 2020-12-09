#include "landbasedwheeled.h"
#include <iostream>
#include "../API/api.h"


void fp::LandBasedWheeled::MoveForward(int x, int y) {
    std::cout << "LandBasedWheeled::MoveForward is called\n";
    fp::API::moveForward();
}
void fp::LandBasedWheeled::TurnLeft(int x, int y) {
    std::cout << "LandBasedWheeled::TurnLeft is called\n";
    fp::API::turnLeft();
}

void fp::LandBasedWheeled::TurnRight(int x, int y) {
    std::cout << "LandBasedTracked::TurnRight is called\n";
    fp::API::turnRight();
}

char fp::LandBasedWheeled::GetDirection() {
    return direction_;
}
