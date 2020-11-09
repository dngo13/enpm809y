//
// Created by diane on 11/4/2020.
//

#include "landbasedtracked.h"
#include <iostream>
void rwa3::LandBasedTracked::GoUp(int x, int y) {
    std::cout << "LandBasedTracked::GoUp is called\n";
}

void rwa3::LandBasedTracked::GoDown(int x, int y) {
    std::cout << "LandBasedTracked::GoDown is called\n";
}

void rwa3::LandBasedTracked::TurnLeft(int x, int y) {
    std::cout << "LandBasedTracked::TurnLeft is called\n";
}

void rwa3::LandBasedTracked::TurnRight(int x, int y) {
    std::cout << "LandBasedTracked::TurnRight is called\n";
}

void rwa3::LandBasedTracked::PickUp(std::string obj) {
    std::cout << "LandBasedTracked::PickUp is called\n";
}

void rwa3::LandBasedTracked::Release(std::string obj) {
    std::cout << "LandBasedTracked::Release is called\n";
}