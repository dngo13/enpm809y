//
// Created by diane on 11/11/20.
//

#include "Maze.h"
#include "../Algorithm/Algorithm.h"
//#include "../Algorithm/Algorithm.cpp"


void fp::Maze::SetWall(fp::Algorithm::Position& current_pos, char direction, bool hasWall) {
    fp::Algorithm::log("Setting walls. ");
    //if (!hasWall)
        fp::API::setWall(current_pos.x, current_pos.y, direction);
}

//std::array<int, 2> current_position,
 void fp::Maze::CheckWall( fp::Algorithm::Position& current_pos, char& direction) {
    fp::Algorithm::log("Checking walls. ");
    //int x{current_position[0]}, y{current_position[0]};
    int x = current_pos.x;
    int y = current_pos.y;
    bool hasWall;
    if (direction == 'N') {
        if (API::wallLeft()) {
            hasWall = true;
            fp::Maze::SetWall(current_pos, 'W',  hasWall);
            // API::setWall(y, 15-x, 'W');
            //west_[x][y] = true;
        }
        else
            hasWall = false;
        if (API::wallFront()) {
            //API::setWall(y, 15-x, 'N');
            hasWall = true;
            fp::Maze::SetWall(current_pos, 'N',  hasWall);
            //north_[x][y] = true;
        }
        else
            hasWall = false;
        if (API::wallRight()) {
            //API::setWall(y, 15-x, 'E');
            hasWall = true;
            fp::Maze::SetWall(current_pos, 'E',  hasWall);
            //east_[x][y] = true;
        }
        else
            hasWall = false;

    if (direction == 'E') {
        if (API::wallLeft()) {
            API::setWall(y, 15-x, 'N');
            //north_[x][y] = true;
        }
        else
            hasWall = false;
        if (API::wallFront()) {
            API::setWall(y, 15-x, 'E');
            //east_[x][y] = true;
        }
        if (API::wallRight()) {
            API::setWall(y, 15-x, 'S');
            //south_[x][y] = true;
        }
    }
    if (direction == 'S') {
        if (API::wallLeft()) {
            API::setWall(y, 15-x, 'E');
            //east_[x][y] = true;
        }
        if (API::wallFront()) {
            API::setWall(y, 15-x, 'S');
            //south_[x][y] = true;
        }
        if (API::wallRight()) {
            API::setWall(y, 15-x, 'W');
            //west_[x][y] = true;
        }
    }
    if (direction == 'W') {
        if (API::wallLeft()) {
            API::setWall(y, 15-x, 'S');
            //south_[x][y] = true;
        }
        if (API::wallFront()) {
            API::setWall(y, 15-x, 'W');
            //west_[x][y] = true;
        }
        if (API::wallRight()) {
            API::setWall(y, 15-x, 'N');
            //north_[x][y] = true;
        }
    }
}

