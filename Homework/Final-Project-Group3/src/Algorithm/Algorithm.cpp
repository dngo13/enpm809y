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

void fp::Algorithm::ClearStack() {
    while(!stack_.empty()){
        stack_.pop();
    }
}

void fp::Algorithm::CallSetMaze() {
    maze.SetCenter();
    maze.SetPerimeterWalls();
    goal_1 = {7, 7};
    goal_2 = {7, 8};
    goal_3 = {8, 7};
    goal_4 = {8, 8};

}

void fp::Algorithm::Solve() {
    if (Maze::MAZE_HEIGHT != API::mazeHeight()) {
        if (Maze::MAZE_WIDTH != API::mazeWidth())
            std::cout << "Error, the maze dimensions must match. " << std::endl;
    }
    API::clearAllColor();
    log("~--~Starting~~--");

    InitializeMaze(position, direction);
    CallSetMaze();
    //  while (true) {
    //  }
    //if (Maze::Unsolvable == true) {
    //    std::cerr << "The maze cannot be solved. " << std::endl;
    //    break;
    //  }

//    while (!fp::API::wallFront()) {
//        fp::API::moveForward();
//        UpdatePosition(direction, 'f', current_pos);
//        fp::Algorithm::CheckWall(current_pos, direction);
//    }
    bool start = true;
    while (true) {
        DFS(start, direction, robot_);
        if (ResetPressed()) {
            reset();
        }
        break;
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

void fp::Algorithm::MoveLeft() {
    fp::API::turnLeft();
    fp::API::moveForward();
}
void fp::Algorithm::MoveRight(){
    fp::API::turnRight();
    fp::API::moveForward();
}

void fp::Algorithm::CheckWall(Position &current_pos, char &current_direction) {
    current_pos.x = curr_node[0];
    current_pos.y = curr_node[1];
    log("Current Node: " + std::to_string(curr_node[0]) + ", "+ std::to_string(curr_node[1]));
    log("Checking walls. ");
    direction = current_direction;
    //Check South
    if (direction == 's') {
        log("south");
        if (fp::API::wallLeft()) {
            fp::API::setWall(current_pos.x, current_pos.y, 'e');
            //SetWall(current_pos, 'e', hasWall);
            log("South - wall left");
        }
        if (fp::API::wallFront()) {
            fp::API::setWall(current_pos.x, current_pos.y, 's');
            //SetWall(current_pos, 's', hasWall);
            log("South - wall front");
        } else if (!fp::API::wallFront()) {
            log("South - no wall front ");
        }
        if (fp::API::wallRight()) {
            fp::API::setWall(current_pos.x, current_pos.y, 'w');
            //SetWall(current_pos, 'w', hasWall);
            log("South - wall right");
        }
    }
    direction = current_direction;
    //Check East
    if (direction == 'e') {
        log("east");
        if (fp::API::wallLeft()) {
            fp::API::setWall(current_pos.x, current_pos.y, 'n');
            //log("Current Node: " + std::to_string(curr_node[0]) + ", "+ std::to_string(curr_node[1]));
            log("East - wall left");

        }
        if (fp::API::wallFront()) {
            fp::API::setWall(current_pos.x, current_pos.y, 'e');
            //SetWall(current_pos, 'e', hasWall);
            //log("Current Node: " + std::to_string(curr_node[0]) + ", "+ std::to_string(curr_node[1]));
            log("East - wall front");
        }
        if (fp::API::wallRight()) {
            fp::API::setWall(current_pos.x, current_pos.y, 's');
            //log("Current Node: " + std::to_string(curr_node[0]) + ", "+ std::to_string(curr_node[1]));
            log("East - wall right");
        }
    }
    direction = current_direction;
    //Check North
    if (direction == 'n') {
        log("north");
        if (fp::API::wallLeft()) {
            fp::API::setWall(current_pos.x, current_pos.y, 'w');
            //SetWall(current_pos, 'w', hasWall);
            //log("Current Node: " + std::to_string(curr_node[0]) + ", "+ std::to_string(curr_node[1]));
            log("North - wall left");
        }
        if (fp::API::wallFront()) {
            fp::API::setWall(current_pos.x, current_pos.y, 'n');
            //SetWall(current_pos, 'n', hasWall);
            //log("Current Node: " + std::to_string(curr_node[0]) + ", "+ std::to_string(curr_node[1]));
            log("North - wall front");
        }
        if (fp::API::wallRight()) {
            fp::API::setWall(current_pos.x, current_pos.y, 'e');
            //SetWall(current_pos, 'e', hasWall);
            //log("Current Node: " + std::to_string(curr_node[0]) + ", "+ std::to_string(curr_node[1]));
            log("North - wall right");
        }
    }
    direction = current_direction;
    //Check West
    if (direction == 'w') {
        log("west");
        if (fp::API::wallLeft()) {
            //SetWall(current_pos, 's', hasWall);
            //log("Current Node: " + std::to_string(curr_node[0]) + ", "+ std::to_string(curr_node[1]));
            fp::API::setWall(current_pos.x, current_pos.y, 's');
        }
        if (fp::API::wallFront()) {
            //SetWall(current_pos, 'w', hasWall);
            //log("Current Node: " + std::to_string(curr_node[0]) + ", "+ std::to_string(curr_node[1]));
            fp::API::setWall(current_pos.x, current_pos.y, 'w');
        }
        if (fp::API::wallRight()) {
            //SetWall(current_pos, 'n', hasWall);
            //log("Current Node: " + std::to_string(curr_node[0]) + ", "+ std::to_string(curr_node[1]));
            fp::API::setWall(current_pos.x, current_pos.y, 'n');
        }
    }
}


void fp::Algorithm::DFS(bool start, char& current_direction, const std::shared_ptr<fp::LandBasedRobot> &robot) {
    std::string dir;
    current_direction = direction;
    dir = current_direction;
    log(dir);
    robot_ = robot;
    curr_node = {current_pos.x, current_pos.y};
    parent_node = curr_node;
    visited_node_[current_pos.x][current_pos.y] = true;
    log("Pushing stack ");
    stack_.push(curr_node);
   // log("Set to south");
   if (start) {
       log(dir);
       if (direction == 'n') {
           visited_node_[curr_node[0] - 1][curr_node[1]] = false;
           fp::API::turnLeft();
           UpdateDirection(current_direction, 'l');
           fp::API::turnLeft();
           UpdateDirection(current_direction, 'l');
       }
   }
   else {
       direction = 'n';
   }

   log(dir);
   log("Checking south");
    //std::array<int, 2> position_array = {current_pos.x, current_pos.y};
    while (curr_node != goal_1 || curr_node != goal_2 || curr_node != goal_3 ||
            curr_node != goal_4) {
        CheckWall(current_pos, current_direction);
        log("Current Node: " + std::to_string(curr_node[0]) + ", "+ std::to_string(curr_node[1]));
        FindNextNode(curr_node, current_direction, path_blocked_);
        log(dir);
        std::string isBlocked;
        isBlocked = path_blocked_;
        log("Blocked?");

        if(!path_blocked_) {
            log("Nope");
            fp::API::moveForward();
            UpdatePosition(current_direction, 'f', current_pos);
            CheckWall(current_pos, current_direction);
            log("Current Node: " + std::to_string(curr_node[0]) + ", "+ std::to_string(curr_node[1]));
            log("Next Node: " + std::to_string(next_node[0]) + ", "+ std::to_string(next_node[1]));
        }
       // CheckWall(current_pos, current_direction);
        //UpdateDirection(current_direction, 'l');
        //log(dir);
        //fp::API::moveForward();


        }
    }

void fp::Algorithm::FindNextNode(std::array<int, 2> curr_node, char current_direction, bool path_blocked_) {
    /**
     * Arrays to define the possible direction of the nodes , north, south, east, west
     */
    std::array<int, 2> north_node = {curr_node[0], curr_node[1]-1};
    std::array<int, 2> east_node = {curr_node[0]+1, curr_node[1]};
    std::array<int, 2> south_node = {curr_node[0], curr_node[1]+1};
    std::array<int, 2> west_node = {curr_node[0] - 1, curr_node[1]};

    //curr_node = stack_.pop();
//
//    if(direction == 'n'){
//        fp::API::turnLeft();
//        UpdateDirection(current_direction, 'l');
//        fp::API::turnLeft();
//        UpdateDirection(current_direction, 'l');
//    }

    next_node = south_node;
    current_direction = 's';
    log("South?");
    log("Current Node: " + std::to_string(curr_node[0]) + ", "+ std::to_string(curr_node[1]));
    log("Next Node: " + std::to_string(next_node[0]) + ", "+ std::to_string(next_node[1]));
    bool path_found = !CheckPath(next_node, visited_node_);
    while (!path_found) {
        bool no_path = CheckPath(next_node, visited_node_);
        if ( no_path ) {
            //Check south, then east
            log("South has been visited or has a wall");
            std::string dir;
            dir = current_direction;
            log(dir);
            next_node = east_node;
            current_direction = 'e';
            log("East?");
            log("Current Node: " + std::to_string(curr_node[0]) + ", "+ std::to_string(curr_node[1]));
            log("Next Node: " + std::to_string(next_node[0]) + ", "+ std::to_string(next_node[1]));
            fp::API::turnLeft();
            UpdateDirection(current_direction, 'l');
            //CheckWall(current_pos, current_direction);
        } else {
            log("Next node found");
            curr_node = next_node;
            stack_.push(curr_node);
            fp::API::setColor(curr_node[0], curr_node[1], 'r');
            path_found = true;
        }
        //Check east, then north
        no_path = CheckPath(next_node, visited_node_);
        if (no_path) {
            log("East has been visited or has a wall");
            next_node = north_node;
            current_direction = 'n';
            log("North?");
            log("Current Node: " + std::to_string(curr_node[0]) + ", "+ std::to_string(curr_node[1]));
            log("Next Node: " + std::to_string(next_node[0]) + ", "+ std::to_string(next_node[1]));
            fp::API::turnLeft();
            UpdateDirection(current_direction, 'l');
            //CheckWall(current_pos, current_direction);

        } else {
            log("Next node found");
            curr_node = next_node;
            stack_.push(curr_node);
            fp::API::setColor(curr_node[0], curr_node[1], 'r');
            path_found = true;
        }
        //Check north, then west
        no_path = CheckPath(next_node, visited_node_);
        if (no_path ) {
            log("North has been visited or has a wall");
            next_node = west_node;
            direction = 'w';
            log("West?");
            log("Current Node: " + std::to_string(curr_node[0]) + ", "+ std::to_string(curr_node[1]));
            log("Next Node: " + std::to_string(next_node[0]) + ", "+ std::to_string(next_node[1]));
            fp::API::turnLeft();
            UpdateDirection(current_direction, 'l');
            //CheckWall(current_pos, current_direction);
        } else {
            log("Next node found");
            curr_node = next_node;
            stack_.push(curr_node);
            fp::API::setColor(curr_node[0], curr_node[1], 'c');
            path_found = true;
        }
        //Check South again
//        no_path = CheckPath(next_node, visited_node_);
//        if ( no_path) {
//            log("West has been visited or has a wall");
//            next_node = south_node;
//            direction = 's';
//            fp::API::turnLeft();
//            UpdateDirection(current_direction, 'l');
//            CheckWall(current_pos, current_direction);
//        } else {
//            log("Next node found");
//            curr_node = next_node;
//            stack_.push(curr_node);
//            fp::API::setColor(curr_node[0], curr_node[1], 'c');
//            path_found = true;
//        }

//        no_path = CheckPath(path_blocked_, next_node, direction);
//        if (is_visited(next_node) || no_path) {
//            log("West has been visited or has a wall");
//            next_node = east_node;
//            direction = 'e';
//        } else {
//            log("Next node found");
//            curr_node = next_node;
//            stack_.push(next_node);
//            fp::API::setColor(curr_node[0], curr_node[1], 'c');
//            no_path = CheckPath(path_blocked_, next_node, direction);
//        }
    }
}


bool fp::Algorithm::CheckPath(std::array<int, 2> next_node, std::array<std::array <bool, 16>, 16> visited_node_) {
    std::string x;
    x = next_node[0];
    std::string y;
    y = next_node[1];
    std::string visited;
    visited = visited_node_[next_node[0]][next_node[1]];
    log("Visited");
    log("----");
    //std::string frontbool;
    //frontbool = fp::API::wallFront();
    //log("Is there a wall");
    //log(frontbool);

    if (visited_node_[next_node[0]][next_node[1]] || fp::API::wallFront()) {
        log("Path blocked");
        path_blocked_ = true;
        return path_blocked_;
    }
    else {
        path_blocked_ = false;
        curr_node = next_node;
        stack_.push(curr_node);
        log("Path not blocked");
        return path_blocked_;
    }
}

