/**
 * Algorithm.h
 */
#ifndef FINAL_PROJECT_GROUP3_ALGORITHM_H
#define FINAL_PROJECT_GROUP3_ALGORITHM_H
#include <iostream>
#include <memory>
#include <stack>
#include "../LandBasedRobot/LandBasedRobot.h"
#include "../Maze/Maze.h"
#include <array>


//DFS Algorithm from S to G
//Down right up left
namespace fp {
    class Algorithm {
    public:
        /**
         * Position structure for the x and y coordinate of the robot
         */
        struct Position{
            int x{0};
            int y{0};
        }position, current_pos;
        /**
         * A method to print out text to the maze simulator
         * @param text
         */
        static void log(const std::string& text);
        /**
         * Function to update the direction of the robot
         * @param current_direction char direction of N/S/E/W
         * @param turn char to specify if the robot is turning left or right
         */
        void UpdateDirection(char& current_direction, char turn);
        /**
         * Function to update the position of the robot
         * @param current_direction char direction of N/S/E/W
         * @param move
         * @param curr_pos
         */
        void UpdatePosition(char current_direction, char move, Position& curr_pos);

        /**
         * Initializes the maze with default settings
         * @param position
         * @param direction
         */
        static void InitializeMaze(fp::Algorithm::Position &position, char& direction);
        /**
         * Starts the setup for the maze and algorithm
         */
        void Solve();
        /**
         * Depth First Search Algorithm to traverse through the maze and save visited nodes
         * @param start tells the algorithm if first time starting it
         * @param current_direction current direction of the robot
         * @param robot
         */
        void DFS(bool start, char& current_direction, const std::shared_ptr<fp::LandBasedRobot> &robot);
        /**
         * If the reset button is pressed
         * @return reset
         */
        bool ResetPressed();
        /**
         * Resets the maze if the button is pressed
         */
        void reset();
        /**
         * Function to set the center and perimeter of the maze
         */
        void CallSetMaze();
        /**
        * CheckWall is a method to check if there is a wall in the front, left, and
        * right side of the robot
        * @param current_position current position of the robot
        * @param direction direction that the robot is facing
        * @return
        */
        void CheckWall(Position &position, char &current_direction);

        /**
         * FindNextNode function checks 1 node forward in every direction and sees if the path is blocked or is visited
         * to determine which direction the robot can go to
         * @param curr_node current node array, for x and y position
         * @param current_direction current direction of the robot
         * @param path_blocked_ boolean to see if the path is blocked
         */
        void FindNextNode(std::array<int, 2> curr_node, char current_direction, bool path_blocked_);
        /**
         * Stack where nodes will be pushed
         */
        std::stack<std::array<int, 2>> stack_;
        /**
         * Shared pointer for the robot
         */
        std::shared_ptr<fp::LandBasedRobot> robot_;

        /**
         * CheckPath function sees if the next node has been visited or a wall
         * @param path_blocked_ boolean to see if path is blocked by a wall
         * @param next_node next node array in terms of position
         * @param visited_node_ 16x16 boolean array to determine if a node has been visited
         * @return true or false if path can be moved to
         */
        bool CheckPath(std::array<int, 2> next_node, std::array<std::array <bool, 16>, 16> visited_node_);
        //Constructor for Algorithm
        Algorithm(): robot_{nullptr},stack_{}, curr_node{}, next_node{}, visited_node_{} {}
        //goal_1{}, goal_2{}, goal_3{}, goal_4{}
        //Destructor
        ~Algorithm() = default;
    protected:
        Maze maze;
        char direction{'n'};
        void ClearStack();
        void MoveLeft();
        void MoveRight();
        /**
         * Defining the nodes of arrays
         */
        std::array<std::array <bool, 16>, 16> visited_node_;
        std::array<int, 2> curr_node;
        std::array<int, 2> next_node;
        std::array<int, 2> parent_node;
        std::array<int, 2> goal_1, goal_2, goal_3, goal_4;
        bool path_found{};
        bool path_blocked_{true};



    }; //-class Algorithm


} //--namespace fp

#endif //FINAL_PROJECT_GROUP3_ALGORITHM_H
