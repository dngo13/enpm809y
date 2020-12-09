/**
 * Maze.h
 */

#ifndef FINAL_PROJECT_GROUP3_MAZE_H
#define FINAL_PROJECT_GROUP3_MAZE_H
#include "../API/api.h"
#include "../Algorithm/Algorithm.h"
#include <iostream>

namespace fp {
    class Maze {
    public:
        const static int MAZE_WIDTH = 16; /**< Define the maze width*/
        const static int MAZE_HEIGHT = 16; /**< Define the maze height*/
        int maze_arr[MAZE_WIDTH][MAZE_HEIGHT]; /**< Define the maze as 16x16 2D array */


        void CheckWall(fp::Algorithm::Position &position, char direction);
        void set_wall(fp::Algorithm::Position& position);


        //static void SetPerimeterWalls(int cell, char direction);
        //std::cout<< "Main started" << std::endl;


    protected:
        char direction{'N'};
        int x_;
        int y_;
        //int cell[x][y];
    }; //-- Maze class
}; //--namespace fp


#endif //FINAL_PROJECT_GROUP3_MAZE_H
