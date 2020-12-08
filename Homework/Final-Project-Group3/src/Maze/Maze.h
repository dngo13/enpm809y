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
          * Initialize center of the maze by setting the color and text of the 4 center tiles
          */
        void SetCenter();
        //fp::Algorithm::Position& position
        /**
         * Set the perimeter walls
         */
        static void SetPerimeterWalls();
        /**
         * Sets the path color as the robot travels
         * @param start_node starting position of the robot
         */
        void SetPathColor(std::array<int, 2> start_node);

        bool Unsolvable;



    }; //-- Maze class
}; //--namespace fp


#endif //FINAL_PROJECT_GROUP3_MAZE_H
