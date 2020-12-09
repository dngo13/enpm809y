

#include "landbasedtracked.h"
#include "../API/api.h"
#include "../Algorithm/Algorithm.h"

char fp::LandBasedTracked::GetDirection() {
    return direction_;
}

void fp::LandBasedTracked::MoveForward(int x, int y, char direction) {
    fp::Algorithm::log("LandBasedTracked::MoveForward is called\n");
    fp::API::moveForward();
}
void fp::LandBasedTracked::TurnLeft() {
    fp::Algorithm::log("LandBasedTracked::TurnLeft is called\n");
    fp::API::turnLeft();
}

void fp::LandBasedTracked::TurnRight() {
    fp::Algorithm::log("LandBasedTracked::TurnRight is called\n");
    fp::API::turnRight();
}
