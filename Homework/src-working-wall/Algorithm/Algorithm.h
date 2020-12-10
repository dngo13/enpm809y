/**
 * Algorithm.h
 */
#ifndef FINAL_PROJECT_GROUP3_ALGORITHM_H
#define FINAL_PROJECT_GROUP3_ALGORITHM_H
#include <iostream>
#include <memory>
#include <stack>
#include "../LandBasedRobot/LandBasedRobot.h"

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
        void UpdateDirection(char& current_direction, char turn);
        void UpdatePosition(char current_direction, char move, Position& curr_pos);
        /**
         * Sets the center of the maze to a color and 'G' characters
         */
        static void SetCenter();
        //fp::Algorithm::Position& position
        void SetPerimeterWalls();
        /**
         * Initializes the maze with default settings
         * @param position
         * @param direction
         */
        static void InitializeMaze(fp::Algorithm::Position &position, char& direction);
        void Solve();

        void DFS(const std::shared_ptr<fp::LandBasedRobot> &robot);
        bool ResetPressed();
        void reset();
        void CheckWall(Position &position, char& direction);
        void SetWall(Position &position, char &direction, bool hasWall);
        std::stack<std::array<int, 2>> stack_;
        std::shared_ptr<fp::LandBasedRobot> robot_;

        int row_num{};
        int col_num{};
        //std::array<std::array<bool, row_num>, col_num> visited_node;
        //bool visited_node[row_num][col_num]{false};
        // visited_node{}
        //Constructor for Algorithm
        Algorithm(): robot_{nullptr},stack_{} {
        }

        //Destructor
        ~Algorithm() = default;
    protected:
        char direction{'N'};

        void ClearStack();

        void MoveLeft();

        void MoveRight();
    }; //-class Algorithm


} //--namespace fp

#endif //FINAL_PROJECT_GROUP3_ALGORITHM_H
