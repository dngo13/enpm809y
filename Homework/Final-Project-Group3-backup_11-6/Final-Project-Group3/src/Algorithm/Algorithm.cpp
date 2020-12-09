/**
 * Algorithm.cpp
 */

#include "Algorithm.h"
#include <iostream>
#include <string>
#include "../API/api.h"
#include "../Maze/Maze.h"
#include "../Maze/Maze.cpp"
#include "../LandBasedRobot/LandBasedRobot.h"

void fp::Algorithm::log(const std::string& text) {
    std::cerr << text << std::endl;
}

/**
 * Initialize center of the maze by setting the color and text of the 4 center tiles
 */
void fp::Algorithm::SetCenter() {
    log("~--~Starting~~--");
    fp::API::setColor(0, 0,  'G');
    fp::API::setText(0, 0, "S");
    fp::API::setText(7, 7, "G");
    fp::API::setColor(7, 7,  'B');
    fp::API::setText(7, 8, "G");
    fp::API::setColor(7, 8,  'B');
    fp::API::setText(8, 7, "G");
    fp::API::setColor(8, 7,  'B');
    fp::API::setText(8, 8, "G");
    fp::API::setColor(8, 8,  'B');
}

//int cell[x][y],
void fp::Algorithm::SetPerimeterWalls() {
    for (int x=0; x < Maze::MAZE_WIDTH, x++;){
        for(int y=0; y< Maze::MAZE_HEIGHT, y++;){
            if (x==0) {
                fp::API::setWall(position.x, position.y, 'W');
            }
            if (y==0){
                fp::API::setWall(position.x, position.y, 'S');
            }
            if (x == Maze::MAZE_WIDTH-1){
                fp::API::setWall(position.x, position.y, 'E');
            }
            if (y == Maze::MAZE_HEIGHT-1) {
                fp::API::setWall(position.x, position.y, 'N');
            }
            //std::cout << "setting fake walls " << std::endl;
        }
    }
}


void fp::Algorithm::Solve() {

    if (Maze::MAZE_HEIGHT != API::mazeHeight())
        if (Maze::MAZE_WIDTH != API::mazeWidth())
            std::cout << "Error, the maze dimensions must match. " << std::endl;
        /**< In class example of moving in the maze*/
    SetCenter();
    SetPerimeterWalls();
    InitializeMaze(position, direction);
    while (true) {
        if (!fp::API::wallLeft()) {
            fp::API::turnLeft();
            UpdateDirection(direction, 'l');
        }
        while (fp::API::wallFront()) {
            fp::API::turnRight();
            UpdateDirection(direction, 'r');
        }
        fp::API::moveForward();
        UpdatePosition(direction, 'f', position);
        log(std::to_string(position.x));
        log(std::to_string(position.y));
        log("--------");

        if ((direction =='N') || (direction=='S') ){
            if (fp::API::wallLeft()) {
                fp::API::setWall(position.x, position.y, 'w');
            }
            if (fp::API::wallRight()){
                fp::API::setWall(position.x, position.y, 'e');
            }
        }
    }
}

void fp::Algorithm::UpdateDirection(char &current_direction, const char turn) {
    log("Turning " + std::string(1,turn));
    if (current_direction=='N') {
        if (turn== 'l')
            current_direction = 'W';
        else
            current_direction = 'E';
    }
    else if (current_direction=='E') {
        if (turn== 'l')
            current_direction = 'N';
        else
            current_direction = 'S';
    }
    else if (current_direction=='S') {
        if (turn== 'l')
            current_direction = 'E';
        else
            current_direction = 'W';
    }
    else if (current_direction=='W') {
        if (turn== 'l')
            current_direction = 'S';
        else
            current_direction = 'N';
    }
    log(std::string(1,current_direction));
}

void fp::Algorithm::UpdatePosition(const char current_direction, const char move, fp::Algorithm::Position &position) {
    if (current_direction == 'N') {
        if (move == 'f')
            position.y++;
        else
            position.y--;
    }
    else if (current_direction == 'E') {
        if (move == 'f')
            position.x++;
        else
            position.x--;
    }
    else if (current_direction == 'S') {
        if (move == 'f')
            position.y--;
        else
            position.y++;
    }
    else if (current_direction == 'W') {
        if (move == 'f')
            position.x--;
        else
            position.x++;
    }
}

void fp::Algorithm::InitializeMaze(fp::Algorithm::Position &position, char& direction) {
    position.x = 0;
    position.y = 0;
    direction = 'N';

}


