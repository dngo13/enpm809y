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
    fp::API::clearAllText();
    fp::API::clearAllColor();
    log("~--~Starting~~--");
    InitializeMaze(position, direction);
    CallSetMaze();

    //if (Maze::Unsolvable == true) {
    //    std::cerr << "The maze cannot be solved. " << std::endl;
    //    break;
    //  }

    bool start = true;
    while (true) {
        DFS(start, direction, robot_);
        start = false;
        if (ResetPressed()) {
            reset();
        }
        break;
    }
}

void fp::Algorithm::UpdateDirection(char &current_direction, const char turn) {
    log("Turning " + std::string(1,turn));
    if (current_direction =='n') {
        if (turn == 'l')
            current_direction = 'w';
        else
            current_direction = 'e';
    }
    else if (current_direction =='e') {
        if (turn == 'l')
            current_direction = 'n';
        else
            current_direction = 's';
    }
    else if (current_direction =='s') {
        if (turn == 'l')
            current_direction = 'e';
        else
            current_direction = 'w';
    }
    else if (current_direction =='w') {
        if (turn == 'l')
            current_direction = 's';
        else
            current_direction = 'n';
    }
    log(std::string(1,current_direction));
    if (turn == 'l')
        fp::API::turnLeft();
    else
        fp::API::turnRight();
}

void fp::Algorithm::UpdatePosition(const char current_direction, const char move, std::array<int, 2> &curr_node) {
    if (current_direction == 'n') {
        if (move == 'f')
            curr_node[1]++;
    }
    if (current_direction == 'e') {
        if (move == 'f')
            curr_node[0]++;
    }
    if (current_direction == 's') {
        if (move == 'f')
            curr_node[1]--;
    }
    if (current_direction == 'w') {
        if (move == 'f')
            curr_node[0]--;
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
    fp::API::ackReset();
    position.x = 0;
    position.y = 0;
    direction = 'n';
}

void fp::Algorithm::CheckWall(std::array<int, 2> curr_node, char &current_direction, std::array<std::array <bool, 16>, 16> visited_node_) {
    log("CheckWall function");
    log("Current Node: " + std::to_string(curr_node[0]) + ", " + std::to_string(curr_node[1]));
    log("Checking walls.");
    //Check South
    if (current_direction == 's') {
        log("south");
        if (fp::API::wallLeft()) {
            fp::API::setWall(curr_node[0], curr_node[1], 'e');
            log("South - wall left");
        }
        if (fp::API::wallRight()) {
            fp::API::setWall(curr_node[0], curr_node[1], 'w');
            log("South - wall right");
        }
        if (fp::API::wallFront()) {
            fp::API::setWall(curr_node[0], curr_node[1], 's');
            log("South - wall front");
        } else if (!fp::API::wallFront()) {
            log("South - no wall front ");
        }
    }
    //Check East
    else if (current_direction == 'e') {
        log("east");
        if (fp::API::wallLeft()) {
            fp::API::setWall(curr_node[0], curr_node[1], 'n');
            log("East - wall left");
        }
        if (fp::API::wallRight()) {
            fp::API::setWall(curr_node[0], curr_node[1], 's');
            log("East - wall right");
        }
        if (fp::API::wallFront()) {
            fp::API::setWall(curr_node[0], curr_node[1], 'e');
            log("East - wall front");
        } else if (!fp::API::wallFront()) {
            log("East - no wall front ");
        }
    }
    //Check North
    else if (current_direction == 'n') {
        log("north");
        if (fp::API::wallLeft()) {
            fp::API::setWall(curr_node[0], curr_node[1], 'w');
            log("North - wall left");
        }
        if (fp::API::wallRight()) {
            fp::API::setWall(curr_node[0], curr_node[1], 'e');
            log("North - wall right");
        }
        if (fp::API::wallFront()) {
            fp::API::setWall(curr_node[0], curr_node[1], 'n');
            log("North - wall front");
        }
        else if (!fp::API::wallFront()) {
            log("North - no wall front ");
        }
    }
    //Check West
    else if (current_direction == 'w') {
        log("west");
        if (fp::API::wallLeft()) {
            fp::API::setWall(curr_node[0], curr_node[1], 's');
            log("West - wall left");
        }
        if (fp::API::wallRight()) {
            fp::API::setWall(curr_node[0], curr_node[1], 'n');
            log("West - wall right");
        }
        if (fp::API::wallFront()) {
            fp::API::setWall(curr_node[0], curr_node[1], 'w');
            log("West - wall front");
        } else if (!fp::API::wallFront()) {
            log("West - no wall front ");
        }
    }

}


void fp::Algorithm::DFS(bool start, char current_direction, const std::shared_ptr<fp::LandBasedRobot> &robot) {
    log("Starting DFS");
    std::string dir;
    //current_direction = direction;
    dir = current_direction;
    log(dir);
    robot_ = robot;
    curr_node = {current_pos.x, current_pos.y};
    visited_node_[curr_node[0]][curr_node[1]] = true;
    log("Pushing stack ");
    stack_.push(curr_node);

    log("Checking if first start");
   if (start) {
       //log(dir);
       if (direction == 'n') {
           current_direction = direction;
           UpdateDirection(current_direction, 'l'); //since the robot starts north it needs to turn left twice
           UpdateDirection(current_direction, 'l'); //to start with checking south
       }
   }
    dir = current_direction;
    log(dir);
    log("While not at goal DFS");

    while (curr_node != goal_1 || curr_node != goal_2 || curr_node != goal_3 ||
           curr_node != goal_4) {
        log("Goal not found.");
        log(dir);
        log("Current Node: " + std::to_string(curr_node[0]) + ", " + std::to_string(curr_node[1]));
        fp::API::setColor(curr_node[0], curr_node[1], 'c');
        FindNextNode(curr_node, current_direction, path_blocked_);
        log("Node Found: " + std::to_string(next_node[0]) + ", " + std::to_string(next_node[1]));
        log(dir);
        fp::API::moveForward();
        UpdatePosition(current_direction, 'f', curr_node);
    }

 }

void fp::Algorithm::FindNextNode(std::array<int, 2> curr_node, char &current_direction, bool path_blocked_) {
    log("Finding next node");
    log("Current Node: " + std::to_string(curr_node[0]) + ", " + std::to_string(curr_node[1]));
    /**
     * Arrays to define the possible direction of the nodes , north, south, east, west
     */
    std::array<int, 2> north_node = {curr_node[0], curr_node[1]+1};
    std::array<int, 2> east_node = {curr_node[0]+1 ,curr_node[1]};
    std::array<int, 2> south_node = {curr_node[0],curr_node[1]-1 };
    std::array<int, 2> west_node = {curr_node[0]-1, curr_node[1] };
    if (current_direction == 'n') {
        next_node = north_node;
        log("Initial next node: NORTH NODE");
    }
    else if (current_direction == 'w') {
        next_node = west_node;
        log("Initial next node: WEST NODE");
    }
    else if (current_direction == 's') {
        next_node = south_node;
        log("Initial next node: SOUTH NODE");
    }
    else if (current_direction == 'e') {
        next_node = east_node;
        log("Initial next node: EAST NODE");
    }

    log("ABOUT TO RUN WHILE PATH NOT FOUND");
    bool dead_end = CheckDeadEnd(curr_node, current_direction);
    CheckWall(curr_node, current_direction, visited_node_);
    while (fp::API::wallFront() || CheckPath(next_node, visited_node_)) {
        log("No way forward.");
        if (current_direction == 'n'){
            next_node = west_node;
            log("Turning. Nest node: WEST NODE");
        }
        else if (current_direction == 'w') {
            next_node = south_node;
            log("Turning. Nest node: SOUTH NODE");
        }
        else if (current_direction == 's') {
            next_node = east_node;
            log("Turning. Nest node: EAST NODE");
        }
        else if (current_direction == 'e') {
            next_node = north_node;
            log("Turning. Nest node: NORTH NODE");
        }
        if (dead_end){
            BackTrack(curr_node, current_direction,visited_node_);
        }
        UpdateDirection(current_direction, 'l');
        CheckWall(curr_node, current_direction, visited_node_);
    }
    log("Next Node Determined");
    stack_.push(next_node);
    visited_node_[next_node[0]][next_node[1]] = true;
}

bool fp::Algorithm::CheckDeadEnd(std::array<int, 2> curr_node, char current_direction) {
    bool backtrack_path = CheckPath(next_node, visited_node_);
    bool dead_end;
    if (backtrack_path) {
        if (fp::API::wallLeft() || fp::API::wallRight()) {
            dead_end = true;
            return dead_end;
        }
    }
    else {
        dead_end = false;
        return dead_end;
    }
    return false;
}
bool fp::Algorithm::CheckPath(std::array<int, 2> next_node, std::array<std::array <bool, 16>, 16> visited_node_) {
    log("Checking if dead end");
    bool visited = visited_node_[next_node[0]][next_node[1]];
    if(visited){
        log("Visited");
        path_blocked_ = true;
        return path_blocked_;
    }
    else {
        log("Not visited");
        //curr_node = next_node;
        path_blocked_ = false;
        log("Path not blocked");
        return path_blocked_;
    }
}

void fp::Algorithm::BackTrack(std::array<int, 2> curr_node, char &current_direction, std::array<std::array<bool, 16>, 16> &visited_node_) {
    log("Backtracking..");
    fp::API::clearColor(curr_node[0], curr_node[1]);
    std::array<int, 2> parent_node; // = {parent_node[0], parent_node[1]};
    parent_node = stack_.top();
    stack_.pop();
    log("Parent node: " + std::to_string(parent_node[0]) + ", " +std::to_string(parent_node[1]));

    while(!fp::API::wallFront() && visited_node_[parent_node[0]][parent_node[1]]){
        fp::API::moveForward();
        UpdatePosition(current_direction, 'f', curr_node);
        if(!visited_node_[next_node[0]][next_node[1]]){
            UpdateDirection(current_direction, 'r');
            break;
        }

    }
}

