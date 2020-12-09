#ifndef MAIN_CPP_LANDBASEDWHEELED_H
#define MAIN_CPP_LANDBASEDWHEELED_H
/**< LandBasedWheeled.h , Derived concrete class*/
#include "../LandBasedRobot/LandBasedRobot.h"
#include "../API/api.h"
#include "../Algorithm/Algorithm.h"
#include <iostream>
#include <memory>
#include <utility>

namespace fp {
    class LandBasedWheeled : public LandBasedRobot {
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
        * LandBasedWheeled Constructor
        * @param name name of the robot
        * @param x x coordinate of the robot
        * @param y y coordinate of the robot
        * @param wheels number of wheels on the robot
        */
        explicit LandBasedWheeled(std::string name="wheeled", int x=1, int y=4, char direction='N'):
            LandBasedRobot(std::move(name), x, y), wheel_number{4},direction_{direction}, speed_{speed},width_{width},
        length_{length}, height_{height}, capacity_{capacity}{
            //std::cout << "Constructor for  " << name_ << " called" << std::endl;
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

        /**< Destructor for LandBasedWheeled*/
        virtual ~LandBasedWheeled(){
            //std::cout << "Destructor for " << name_ << " called" << std::endl;
        };

    protected:
        int wheel_number; /**< Number of wheels mounted on the robot */
        const std::string name_; /**< Name of the robot */
        double speed_{}; /**< Driving speed of the robot */
        double width_{}; /**< Width of the base of the robot */
        double length_{}; /**< Width of the base of the robot */
        double height_{}; /**< Height of the base of the robot */
        double capacity_{}; /**< Height of the base of the robot */
        int x_{}; /**< x coordinate of the robot */
        int y_{}; /**< y coordinate of the robot */
        char direction_{'N'}; /**< Direction that the robot is facing in the maze*/
    };//--class LandBasedWheeled

}//--namespace fp
#endif //MAIN_CPP_LANDBASEDWHEELED_H
