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
}

void fp::Algorithm::UpdatePosition(const char current_direction, const char move, std::array<int, 2> &curr_node) {
    if (current_direction == 'n') {
        if (move == 'f')
            curr_node[1]++;
        else
            curr_node[1]--;
        //log("Current node" + std::to_string(curr_node[1]) + "," + (std::to_string(curr_node[0])));
    }
    if (current_direction == 'e') {
        if (move == 'f')
            curr_node[0]++;
//        else
//            curr_node[0]--;
        //log("Current node" + std::to_string(curr_node[1]) + "," + (std::to_string(curr_node[0])));

    }
    if (current_direction == 's') {
        log(std::to_string(curr_node[0]));
        log(std::to_string(curr_node[1]));
        if (move == 'f')
            curr_node[1]--;
        else
            curr_node[1]++;
        //log("Current node" + std::to_string(curr_node[1]) + "," + (std::to_string(curr_node[0])));
    }
    if (current_direction == 'w') {
        if (move == 'f')
            curr_node[0]--;
//        else
//            curr_node[0]++;
        //log("Current node" + std::to_string(curr_node[1]) + "," + (std::to_string(curr_node[0])));
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
    //curr_node = {curr_node[0], curr_node[1]};
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
            fp::API::turnLeft();
            UpdateDirection(current_direction, 'l');
        } else if (!fp::API::wallFront()) {
            log("South - no wall front ");
        }
    }
    //Check East
    else if (current_direction == 'e') {
        log("east");
        if (fp::API::wallLeft()) {
            fp::API::setWall(curr_node[0], curr_node[1], 'n');
            //log("Current Node: " + std::to_string(curr_node[0]) + ", "+ std::to_string(curr_node[1]));
            log("East - wall left");
        }
        if (fp::API::wallRight()) {
            fp::API::setWall(curr_node[0], curr_node[1], 's');
            //log("Current Node: " + std::to_string(curr_node[0]) + ", "+ std::to_string(curr_node[1]));
            log("East - wall right");
        }
        if (fp::API::wallFront()) {
            fp::API::setWall(curr_node[0], curr_node[1], 'e');
            //log("Current Node: " + std::to_string(curr_node[0]) + ", "+ std::to_string(curr_node[1]));
            log("East - wall front");
            fp::API::turnLeft();
            UpdateDirection(current_direction, 'l');
        } else if (!fp::API::wallFront()) {
            log("East - no wall front ");
        }
    }
    //Check North
    else if (current_direction == 'n') {
        log("north");
        if (fp::API::wallLeft()) {
            fp::API::setWall(curr_node[0], curr_node[1], 'w');
            //log("Current Node: " + std::to_string(curr_node[0]) + ", "+ std::to_string(curr_node[1]));
            log("North - wall left");
        }
        if (fp::API::wallRight()) {
            fp::API::setWall(curr_node[0], curr_node[1], 'e');
            //log("Current Node: " + std::to_string(curr_node[0]) + ", "+ std::to_string(curr_node[1]));
            log("North - wall right");
        }
        if (fp::API::wallFront()) {
            fp::API::setWall(curr_node[0], curr_node[1], 'n');
            //log("Current Node: " + std::to_string(curr_node[0]) + ", "+ std::to_string(curr_node[1]));
            log("North - wall front");
            fp::API::turnLeft();
            UpdateDirection(current_direction, 'l');
        }if (fp::API::wallFront() && fp::API::wallLeft()){
            log("Left corner blocked, turning right");
            fp::API::turnRight();
            UpdateDirection(current_direction, 'r');
        }
        else if (!fp::API::wallFront()) {
            log("North - no wall front ");
        }
    }
    //Check West
    else if (current_direction == 'w') {
        log("west");
        if (fp::API::wallLeft()) {
            //log("Current Node: " + std::to_string(curr_node[0]) + ", "+ std::to_string(curr_node[1]));
            fp::API::setWall(curr_node[1], curr_node[0], 's');
        }
        if (fp::API::wallRight()) {
            //log("Current Node: " + std::to_string(curr_node[0]) + ", "+ std::to_string(curr_node[1]));
            fp::API::setWall(curr_node[1], curr_node[0], 'n');
        }
        if (fp::API::wallFront()) {
            //log("Current Node: " + std::to_string(curr_node[0]) + ", "+ std::to_string(curr_node[1]));
            fp::API::setWall(curr_node[1], curr_node[0], 'w');
            UpdateDirection(current_direction, 'l');
            current_direction = 's';
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
    parent_node = curr_node;
    visited_node_[curr_node[1]][curr_node[0]] = true;

    log("Pushing stack ");
    stack_.push(curr_node);

    log("Checking if first start");
   if (start) {
       //log(dir);
       if (direction == 'n') {
           current_direction = direction;
           //visited_node_[curr_node[1] + 1][curr_node[0]] = false;
           fp::API::turnLeft();
           UpdateDirection(current_direction, 'l');
           fp::API::turnLeft();
           UpdateDirection(current_direction, 'l');
       }
   }
    dir = current_direction;
    log(dir);
    log("While not at goal DFS");
    while (curr_node != goal_1 || curr_node != goal_2 || curr_node != goal_3 ||
            curr_node != goal_4) {
        log("Checking for walls");
        dir = current_direction;
        log(dir);
       // CheckWall(curr_node, current_direction);
        FindNextNode(curr_node, current_direction, path_blocked_);
        //dir = current_direction;
        //log(dir);

        path_blocked_ = CheckPath(next_node, visited_node_);
        log("Blocked?");


        CheckWall(curr_node, current_direction, visited_node_);
        while(!path_blocked_) {
            log("set color");
            fp::API::setColor(curr_node[0], curr_node[1], 'c');
            log("Nope, move forward");
            fp::API::moveForward();
            CheckWall(curr_node, current_direction, visited_node_);
            UpdatePosition(current_direction, 'f', curr_node);
            fp::API::setColor(curr_node[0], curr_node[1], 'c');
            //CheckWall(curr_node, current_direction);
            log("Current Node: " + std::to_string(curr_node[0]) + ", " + std::to_string(curr_node[1]));
            log("Next Node: " + std::to_string(next_node[0]) + ", " + std::to_string(next_node[1]));
//            path_blocked_ = CheckPath(next_node, visited_node_);
            if(path_blocked_)
                break;
        }
      //  CheckPath(next_node, visited_node_);

//        while(path_blocked_){
//            log(dir);
//            CheckPath(next_node, visited_node_);
//            CheckWall(curr_node, current_direction);
//            //fp::API::turnLeft();
//            //CheckPath(next_node, visited_node_);
//            //UpdateDirection(current_direction, 'l');
//            CheckWall(curr_node, current_direction);
//            if(!path_blocked_)
//                break;
//        }

        }
    }

void fp::Algorithm::FindNextNode(std::array<int, 2> curr_node, char &current_direction, bool path_blocked_) {
    log("Finding next node");
    CheckWall(curr_node, current_direction, visited_node_);
    log("Current Node: " + std::to_string(curr_node[1]) + ", " + std::to_string(curr_node[0]));
    /**
     * Arrays to define the possible direction of the nodes , north, south, east, west
     */
    //std::array<int, 2> north_node = {curr_node[1]+1, curr_node[0]};
    std::array<int, 2> north_node = {curr_node[0], curr_node[1]+1};
    std::array<int, 2> east_node = {curr_node[0]+1 ,curr_node[1]};
    std::array<int, 2> south_node = {curr_node[0],curr_node[1]-1 };
    std::array<int, 2> west_node = {curr_node[0]-1, curr_node[1] };

    if(current_direction == 'n' && fp::API::wallFront()) {
        next_node = west_node;
        log("WEST NODE");
        next_node = {curr_node[0] + next_node[0], curr_node[1] + next_node[1]};
        log("Next Node: " + std::to_string(next_node[0]) + ", " + std::to_string(next_node[1]));
    }
    else if(current_direction == 'w' && fp::API::wallFront()) {
        next_node = south_node;
        log("SOUTH NODE");
        next_node = {curr_node[0] + next_node[0], curr_node[1] + next_node[1]};
        log("Next Node: " + std::to_string(next_node[0]) + ", " + std::to_string(next_node[1]));
    }
    else if(current_direction == 's' && fp::API::wallFront()) {
        next_node = east_node;
        log("EAST NODE");
        next_node = {curr_node[0] + next_node[0], curr_node[1] + next_node[1]};
        log("Next Node: " + std::to_string(next_node[0]) + ", " + std::to_string(next_node[1]));
    }
    else if(current_direction == 'e' && fp::API::wallFront()) {
        next_node = north_node;
        log("NORTH NODE");
        next_node = {curr_node[0] + next_node[0], curr_node[1] + next_node[1]};
        log("Next Node: " + std::to_string(next_node[0]) + ", " + std::to_string(next_node[1]));
    }
    //Replace is path with wall front check
    log("ABOUT TO RUN WHILE PATH NOT FOUND");
    bool is_path;
    while (fp::API::wallFront()) {
        log("INSIDE WHILE LOOP PLS WORKERINO");
        is_path = !CheckPath(next_node, visited_node_); // meaning there is a path found
        std::string dir;
        dir = current_direction;
        log(dir);
        if(is_path && (current_direction == 'w')) {
            next_node = south_node;
            next_node = {curr_node[0] + next_node[0], curr_node[1] + next_node[1]};
            current_direction = 's';
            log("South?");
            log("Current Node: " + std::to_string(curr_node[0]) + ", " + std::to_string(curr_node[1]));
            log("Next Node: " + std::to_string(next_node[0]) + ", " + std::to_string(next_node[1]));
        }
        else if (is_path && (current_direction == 's')) {
            //Check south, then east
            log("Currently South and checking path");
            log(dir);
            next_node = east_node;
            log("East?");
            next_node = {curr_node[0] + next_node[0], curr_node[1] + next_node[1]};
            log("Current Node: " + std::to_string(curr_node[0]) + ", " + std::to_string(curr_node[1]));
            log("Next Node: " + std::to_string(next_node[0]) + ", " + std::to_string(next_node[1]));
            CheckWall(curr_node, current_direction, visited_node_);
            dir = current_direction;
            log(dir);
        }
        //Check east, then north
        else if (is_path && (current_direction == 'e') ) {
            log("Currently East and checking path");
            next_node = north_node;
            log("North?");
            next_node = {curr_node[0] + next_node[0], curr_node[1] + next_node[1]};
            log("Current Node: " + std::to_string(curr_node[0]) + ", "+ std::to_string(curr_node[1]));
            log("Next Node: " + std::to_string(next_node[0]) + ", "+ std::to_string(next_node[1]));
            CheckWall(curr_node, current_direction , visited_node_);
            dir = current_direction;
            log(dir);
        }
        //Check north, then west
        else if (is_path && (current_direction == 'n')) {
            log("Currently North and checking path");
            next_node = west_node;
            log("West?");
            next_node = {curr_node[0] + next_node[0], curr_node[1] + next_node[1]};
            log("Current Node: " + std::to_string(curr_node[0]) + ", "+ std::to_string(curr_node[1]));
            CheckWall(curr_node, current_direction, visited_node_);
            log("Next Node: " + std::to_string(next_node[0]) + ", "+ std::to_string(next_node[1]));
            dir = current_direction;
            log(dir);
        }
        else {
            is_path = true;
            log("Next node found");
            fp::API::setColor(curr_node[0], curr_node[1], 'c');
            // curr_node = {curr_node[1]+next_node[1], curr_node[0]+next_node[0]};
            stack_.push(curr_node);
            //fp::API::setColor(curr_node[1], curr_node[0], 'c');
            path_found = true;
            dir = current_direction;
            log(dir);
        }
    }
}

bool fp::Algorithm::CheckPath(std::array<int, 2> next_node, std::array<std::array <bool, 16>, 16> visited_node_) {
    bool visited = visited_node_[next_node[1]][next_node[0]];
    if(visited){
        log("Visited");
        if (fp::API::wallFront()) {
            log("Path blocked");
            path_blocked_ = true;
            return path_blocked_;
        }
        return path_blocked_;
    }
    else {
        log("Not visited");
        curr_node = next_node;
        stack_.push(curr_node);
        path_blocked_ = false;
        log("Path not blocked");
        return path_blocked_;
    }
}

