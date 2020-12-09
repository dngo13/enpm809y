#ifndef MAIN_CPP_LANDBASEDTRACKED_H
#define MAIN_CPP_LANDBASEDTRACKED_H

#include <iostream>
#include <memory>
#include <utility>
#include "../LandBasedRobot/LandBasedRobot.h"
#include "../API/api.h"

namespace fp {

    class LandBasedTracked : public LandBasedRobot {
    public:
        /**
         * The following are accessors to get the required derived attributes
         * from the base class (LandBasedRobot)
         */
        double speed = LandBasedRobot::get_speed();
        double width = LandBasedRobot::get_width();
        double length = LandBasedRobot::get_length();
        double height = LandBasedRobot::get_height();
        double capacity = LandBasedRobot::get_capacity();

        /**
         * LandBasedTracked Constructor
         * @param name name of the robot
         * @param x x coordinate of the robot
         * @param y y coordinate of the robot
         * @param direction direction that the robot is facing in the maze
         */
        explicit LandBasedTracked(std::string name="tracked", int x=0, int y=0, char direction='N'):
            //name_{name}, x_{x}, y_{y}{
            LandBasedRobot(std::move(name), x, y), direction_{direction}, speed_{speed},width_{width},
            length_{length}, height_{height}, capacity_{capacity} , track_type_{nullptr}{
            //std::cout << "Constructor for " << name_ <<  " called" << std::endl;
        };

        /**
         * Virtual GetDirection Method
         * Get the direction of the robot in the maze
         * @param x x coordinate of the robot
         * @param y y coordinate of the robot
        */
        virtual char GetDirection() override;
        /**
          * Virtual MoveForward Method
          * Moves the robot forward in the maze
          * @param x x coordinate of the robot
          * @param y y coordinate of the robot
        */
        virtual void MoveForward(int x, int y, char direction) override;
        /**
         * Virtual TurnLeft Method
         * Moves the robot left in the maze
         * @param x x coordinate of the robot
         * @param y y coordinate of the robot
         */
        void TurnLeft() override;
        /**
       * Virtual TurnRight Method
       * Moves the robot right in the maze
       * @param x x coordinate of the robot
       * @param y y coordinate of the robot
       */
        void TurnRight() override;

        /**< Destructor for LandBasedTracked*/
        virtual ~LandBasedTracked(){
        //    std::cout << "Destructor for " << name_ << " called" << std::endl;
        };

    protected:
        std::shared_ptr<std::string> track_type_; /** Type of track mounted on the robot */
        const std::string name_; /**< Name of the robot */
        double speed_{}; /**< Driving speed of the robot */
        double width_{}; /**< Width of the base of the robot */
        double length_{}; /**< Width of the base of the robot */
        double height_{}; /**< Height of the base of the robot */
        double capacity_{}; /**< Height of the base of the robot */
        int x_{}; /**< x coordinate of the robot */
        int y_{}; /**< y coordinate of the robot */
        char direction_{'N'}; /**< Direction that the robot is facing in the maze*/
    };//--class LandBasedTracked

}//--namespace fp

#endif //MAIN_CPP_LANDBASEDTRACKED_H
