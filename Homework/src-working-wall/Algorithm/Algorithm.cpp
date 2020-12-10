/**
 * Algorithm.cpp
 */

#include "Algorithm.h"
#include <iostream>
#include <string>
#include "../API/api.h"
#include "../Maze/Maze.h"
#include "../LandBasedRobot/LandBasedRobot.h"

void fp::Algorithm::log(const std::string& text) {
    std::cerr << text << std::endl;

}

void fp::Algorithm::ClearStack() {
    while(!stack_.empty()){
        stack_.pop();
    }
}

/**
 * Initialize center of the maze by setting the color and text of the 4 center tiles
 */
void fp::Algorithm::SetCenter() {
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

void fp::Algorithm::SetPerimeterWalls() {
    for (int x=0; x < Maze::MAZE_WIDTH; x++){
        for(int y=0; y < Maze::MAZE_HEIGHT; y++){
            if (x == 0) {
                fp::API::setWall(x, y, 'w');
            }
            if (y == 0) {
                fp::API::setWall(x,y , 's');
            }
            if (x == 15){
                fp::API::setWall(x, y, 'e');
            }
            if (y == (Maze::MAZE_HEIGHT - 1)) {
                fp::API::setWall(x, y, 'n');
            }
        }
    }

}

void fp::Algorithm::Solve() {
    if (Maze::MAZE_HEIGHT != API::mazeHeight()) {
        if (Maze::MAZE_WIDTH != API::mazeWidth())
            std::cout << "Error, the maze dimensions must match. " << std::endl;
    }
    log("~--~Starting~~--");

    InitializeMaze(position, direction);
    SetPerimeterWalls();

//    //  while (true) {
    API::clearAllColor();

    API::setColor(0, 0, 'G');
    SetCenter();

    //  }
        //if (Maze::Unsolvable == true) {
        //    std::cerr << "The maze cannot be solved. " << std::endl;
        //    break;
        //  }
        //std::array<int, 2> &current_position, char &direction


        while(!fp::API::wallFront()) {
            fp::API::moveForward();
            UpdatePosition(direction, 'f', current_pos);
            fp::Algorithm::CheckWall(current_pos,  direction);

//            if (direction == 'N') {
//                if (API::wallLeft()) {
//                    fp::API::setWall(current_pos.x, current_pos.y, 'w');
//                    }
//                if (API::wallRight()) {
//                    fp::API::setWall(current_pos.x, current_pos.y, 'e');
//                }
//            }
        }

//            if (!fp::API::wallLeft()) {
//                fp::API::turnLeft();
//                UpdateDirection(direction, 'l');
//            }
//            while (fp::API::wallFront()) {
//                fp::API::turnRight();
//                UpdateDirection(direction, 'r');
//            }
//            fp::API::moveForward();
//            UpdatePosition(direction, 'f', position);

    if (ResetPressed()) {
        reset();
//        log(std::to_string(position.x));
//        log(std::to_string(position.y));
//        log("--------");

    }
}

void fp::Algorithm::UpdateDirection(char &current_direction, const char turn) {
    log("Turning " + std::string(1,turn));
    if (current_direction=='n') {
        if (turn== 'l')
            current_direction = 'w';
        else
            current_direction = 'e';
    }
    else if (current_direction=='e') {
        if (turn== 'l')
            current_direction = 'n';
        else
            current_direction = 's';
    }
    else if (current_direction=='s') {
        if (turn== 'l')
            current_direction = 'e';
        else
            current_direction = 'w';
    }
    else if (current_direction=='w') {
        if (turn== 'l')
            current_direction = 's';
        else
            current_direction = 'n';
    }
    log(std::string(1,current_direction));
}

void fp::Algorithm::UpdatePosition(const char current_direction, const char move, Position &curr_pos) {
    if (current_direction == 'n') {
        if (move == 'f')
            curr_pos.y++;
        else
            curr_pos.y--;
    }
    else if (current_direction == 'e') {
        if (move == 'f')
            curr_pos.x++;
        else
            curr_pos.x--;
    }
    else if (current_direction == 's') {
        if (move == 'f')
            curr_pos.y--;
        else
            curr_pos.y++;
    }
    else if (current_direction == 'w') {
        if (move == 'f')
            curr_pos.x--;
        else
            curr_pos.x++;
    }
}

void fp::Algorithm::InitializeMaze(Position &position, char& direction) {
    position.x = 0;
    position.y = 0;
    direction = 'n';

}

bool fp::Algorithm::ResetPressed() {
    return API::wasReset();
}

void fp::Algorithm::reset() {
    API::ackReset();
    position.x = 0;
    position.y = 0;
    direction = 'n';
}

void fp::Algorithm::DFS(const std::shared_ptr<fp::LandBasedRobot> &robot) {
    robot_ = robot;
    char current_direction{robot->GetDirection()};
}

void fp::Algorithm::MoveLeft() {
    fp::API::turnLeft();
    fp::API::moveForward();
}
void fp::Algorithm::MoveRight(){
    fp::API::turnRight();
    fp::API::moveForward();
}

void fp::Algorithm::CheckWall(Position &current_pos, char &direction) {
    log("Checking walls. ");
    bool hasWall;
    if (direction == 'n') {
        if (fp::API::wallLeft()) {
            fp::API::setWall(current_pos.x, current_pos.y, 'w');
            log(std::to_string(current_pos.x));
            log(std::to_string(current_pos.y));
            log("--------------");
//            hasWall = true;
//            SetWall(current_pos, 'w', hasWall);
            //  } else
            // hasWall = false;
            if (fp::API::wallFront()) {
                fp::API::setWall(current_pos.x, current_pos.y, 'n');
                log(std::to_string(current_pos.x));
                log(std::to_string(current_pos.y));
                log("--------------");
//            hasWall = true;
//            SetWall(current_pos, 'n', hasWall);
                //} else
                //   hasWall = false;
            }
            if (fp::API::wallRight()) {
                fp::API::setWall(current_pos.x, current_pos.y, 'e');
                log(std::to_string(current_pos.x));
                log(std::to_string(current_pos.y));
                log("--------------");
                //hasWall = true;
                //SetWall(current_pos, 'e', hasWall);
                //} else
                //   hasWall = false;
            }
        }
    }

    if (direction == 'e') {
        if (fp::API::wallLeft()) {
            fp::API::setWall(current_pos.x, current_pos.y, 'n');
        }
//            hasWall = true;
//            SetWall(current_pos, 'n', hasWall);
//        } else
//            hasWall = false;
        if (fp::API::wallFront()) {
            fp::API::setWall(current_pos.x, current_pos.y, 'e');
        }
//            hasWall = true;
//            SetWall(current_pos, 'e', hasWall);
        //}
        if (fp::API::wallRight()) {
            fp::API::setWall(current_pos.x, current_pos.y, 's');
//            hasWall = true;
//            SetWall(current_pos, 's', hasWall);
        }
    }

//        if (direction == 's') {
//            if (fp::API::wallLeft()) {
//                hasWall = true;
//                SetWall(current_pos, 'w', hasWall);
//                //API::setWall(y, 15 - x, 'e');
//                //east_[x][y] = true;
//            }
//            if (fp::API::wallFront()) {
//                API::setWall(y, 15 - x, 's');
//                //south_[x][y] = true;
//            }
//            if (fp::API::wallRight()) {
//                hasWall = true;
//                SetWall(current_pos, 'w', hasWall);
//                //API::setWall(y, 15 - x, 'w');
//                //west_[x][y] = true;
//            }
//        }
//        if (direction == 'w') {
//            if (fp::API::wallLeft()) {
//                hasWall = true;
//                SetWall(current_pos, 'w', hasWall);
//            }
//            if (fp::API::wallFront()) {
//                hasWall = true;
//                SetWall(current_pos, 'w', hasWall);
//            }
//            if (fp::API::wallRight()) {
//                hasWall = true;
//                SetWall(current_pos, 'w', hasWall);
//            }
//        }
    }

void fp::Algorithm::SetWall(Position &current_pos, char &direction, bool hasWall) {
    fp::Algorithm::log("Setting walls. ");
    //if (!hasWall)
    fp::API::setWall(current_pos.x, current_pos.y, direction);
}