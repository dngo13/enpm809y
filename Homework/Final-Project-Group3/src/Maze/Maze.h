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

        /**
          * Initialize center of the maze by setting the color and text of the 4 center tiles
          */
        void SetCenter();
        //fp::Algorithm::Position& position
        /**
         * Set the perimeter walls
         */
        static void SetPerimeterWalls();


        bool Unsolvable;



    }; //-- Maze class
}; //--namespace fp


#endif //FINAL_PROJECT_GROUP3_MAZE_H
