#include "landbasedwheeled.h"
#include <iostream>

void fp::LandBasedWheeled::GoUp(int x, int y) {
    std::cout << "LandBasedWheeled::GoUp is called\n";
}

void fp::LandBasedWheeled::GoDown(int x, int y) {
    std::cout << "LandBasedWheeled::GoDown is called\n";
}

void fp::LandBasedWheeled::TurnLeft(int x, int y) {
    std::cout << "LandBasedWheeled::TurnLeft is called\n";
}

void fp::LandBasedWheeled::TurnRight(int x, int y) {
    std::cout << "LandBasedWheeled::TurnRight is called\n";
}

void fp::LandBasedWheeled::PickUp(std::string obj) {
    std::cout << "LandBasedWheeled::PickUp is called\n";
}

void fp::LandBasedWheeled::Release(std::string obj) {
    std::cout << "LandBasedWheeled::Release is called\n";
}

