#ifndef MAIN_CPP_LANDBASEDWHEELED_H
#define MAIN_CPP_LANDBASEDWHEELED_H
/**< LandBasedWheeled.h , Derived concrete class*/
#include "../LandBasedRobot/LandBasedRobot.h"
#include <iostream>
#include <memory>

namespace fp {
    class LandBasedWheeled : public LandBasedRobot {
    public:
       /**
        * LandBasedWheeled Constructor
        * @param name name of the robot
        * @param x x coordinate of the robot
        * @param y y coordinate of the robot
        * @param wheels number of wheels on the robot
        */
        explicit LandBasedWheeled(std::string name="wheeled", int x=1, int y=4, int wheels=4 ):
            LandBasedRobot(name, x, y), wheel_number{wheels} {
            //std::cout << "Constructor for  " << name_ << " called" << std::endl;
        };
        /**
        * Virtual GoUp Method
        * Moves the robot up in the maze
        * @param x x coordinate of the robot
        * @param y y coordinate of the robot
        */
        void GoUp(int x, int y) override;
        /**
           * Virtual GoDown Method
           * Moves the robot down in the maze
           * @param x x coordinate of the robot
           * @param y y coordinate of the robot
           */
        void GoDown(int x, int y) override;
        /**
         * Virtual TurnLeft Method
         * Moves the robot left in the maze
         * @param x x coordinate of the robot
         * @param y y coordinate of the robot
         */
        void TurnLeft(int x, int y) override;
        /**
       * Virtual TurnRight Method
       * Moves the robot right in the maze
       * @param x x coordinate of the robot
       * @param y y coordinate of the robot
       */
        void TurnRight(int x, int y) override;
        /**
       * Virtual PickUp Method
       * Arm picks up an object
       * @param obj
       */
        void PickUp(std::string obj) override;
        /**
        * Virtual Release Method
        * Arm release an object
        * @param obj
        */
        void Release(std::string obj) override;
        /**
         * Get the x coordinate of the robot
         * @return
         */
        int get_x() const {
            return x_;
        };
        /**
       * Get the y coordinate of the robot
       * @return
       */
        int get_y() const {
            return y_;
        };

        /**< Destructor for LandBasedWheeled*/
        virtual ~LandBasedWheeled(){
            //std::cout << "Destructor for " << name_ << " called" << std::endl;
        };

    protected:
        const int wheel_number; /**< Number of wheels mounted on the robot */
        std::shared_ptr<std::string> wheel_type; /** Type of wheels mounted on the robot */
        const std::string name_; /**< Name of the robot */
        double speed_{}; /**< Driving speed of the robot */
        double width_{}; /**< Width of the base of the robot */
        double length_{}; /**< Width of the base of the robot */
        double height_{}; /**< Height of the base of the robot */
        double capacity_{}; /**< Height of the base of the robot */
        int x_; /**< x coordinate of the robot */
        int y_; /**< y coordinate of the robot */
    };//--class LandBasedWheeled

}//--namespace fp
#endif //MAIN_CPP_LANDBASEDWHEELED_H
