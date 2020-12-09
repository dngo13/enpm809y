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
        std::array<std::array<bool, 16>, 2> north_;
        std::array<std::array<bool, 16>, 2> south_;
        std::array<std::array<bool, 16>, 2> east_;
        std::array<std::array<bool, 16>, 2> west_;

        /**
         * Constructor for maze
         */
        Maze(): north_{}, south_{}, east_{}, west_{} {}
        /**
         * CheckWall is a method to check if there is a wall in the front, left, and
         * right side of the robot
         * @param current_position current position of the robot
         * @param direction direction that the robot is facing
         * @return
         */
        //bool CheckWall(std::array<int, 2> current_position, char direction);
        void CheckWall(fp::Algorithm::Position& current_pos, char& direction);
        /**
         * SetWall is a method to set a wall after the robot has found a wall
         * @param position
         */
        void SetWall(fp::Algorithm::Position& current_pos, char direction, bool hasWall);

        bool Unsolvable;

        //static void SetPerimeterWalls(int cell, char direction);
        //std::cout<< "Main started" << std::endl;



    }; //-- Maze class
}; //--namespace fp


#endif //FINAL_PROJECT_GROUP3_MAZE_H
