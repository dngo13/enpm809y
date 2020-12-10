/**
 * Algorithm.h
 */
#ifndef FINAL_PROJECT_GROUP3_ALGORITHM_H
#define FINAL_PROJECT_GROUP3_ALGORITHM_H
#include <iostream>
#include <memory>
#include "../LandBasedRobot/LandBasedRobot.h"

//DFS Algorithm from S to G
//Down right up left
namespace fp {
    class Algorithm {
    public:
        struct Position{
            int x{0};
            int y{0};
        }position;
        static void log(const std::string& text);
        void UpdateDirection(char& current_direction, char turn);
        void UpdatePosition(char current_direction, char move, Position& position);
        static void SetCenter();
        //fp::Algorithm::Position& position
        void SetPerimeterWalls();
        static void InitializeMaze(fp::Algorithm::Position &position, char& direction);
        void Solve();
    protected:
        char direction{'N'};

    }; //-class Algorithm


} //--namespace fp

#endif //FINAL_PROJECT_GROUP3_ALGORITHM_H
