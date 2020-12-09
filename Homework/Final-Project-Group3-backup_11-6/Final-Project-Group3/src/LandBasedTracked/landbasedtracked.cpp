

#include "landbasedtracked.h"
#include "../API/api.h"
#include "../Algorithm/Algorithm.h"

char fp::LandBasedTracked::GetDirection() {
    return direction_;
}

void fp::LandBasedTracked::MoveForward(int x, int y) {
    fp::Algorithm::log("LandBasedTracked::MoveForward is called\n");
    fp::API::moveForward();
}
void fp::LandBasedTracked::TurnLeft(int x, int y) {
    fp::Algorithm::log("LandBasedTracked::TurnLeft is called\n");
    fp::API::turnLeft();
}

void fp::LandBasedTracked::TurnRight(int x, int y) {
    fp::Algorithm::log("LandBasedTracked::TurnRight is called\n");
    fp::API::turnRight();
}
