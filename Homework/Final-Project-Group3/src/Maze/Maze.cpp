//
// Created by diane on 11/11/20.
//

#include "Maze.h"

#include "../Algorithm/Algorithm.h"
//#include "../Algorithm/Algorithm.cpp"



void fp::Maze::SetCenter() {
    fp::API::setColor(0, 0,  'G');
    fp::API::setColor(7, 7,  'B');
    fp::API::setColor(7, 8,  'B');
    fp::API::setColor(8, 7,  'B');
    fp::API::setColor(8, 8,  'B');
    fp::API::setText(0, 0, "S");
    fp::API::setText(7, 7, "G");
    fp::API::setText(7, 8, "G");
    fp::API::setText(8, 7, "G");
    fp::API::setText(8, 8, "G");

}

void fp::Maze::SetPerimeterWalls() {
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


