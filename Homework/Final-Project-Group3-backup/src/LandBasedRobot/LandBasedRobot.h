#ifndef MAIN_CPP_LANDBASEDROBOT_H
#define MAIN_CPP_LANDBASEDROBOT_H
/**< LandBasedRobot.h , Base abstract class*/
#include <string>
#include <iostream>
#include <utility>

namespace fp {
    class LandBasedRobot { //--abstract class
     public:
        /**
         * LandBasedRobot Constructor
         * @param name name of the robot
         * @param x x coordinate of the robot
         * @param y y coordinate of the robot
         */
        explicit LandBasedRobot(std::string name="robot", int x=0, int y=0) :
            name_{name}, x_{x}, y_{y}{
            //std::cout << "Constructor for " << name_ << " called" << std::endl;
            }
         /**
          * Virtual GoUp Method
          * Moves the robot up in the maze
          * @param x x coordinate of the robot
          * @param y y coordinate of the robot
          */
        virtual void GoUp(int x, int y)= 0; //-- pure virtual method
        /**
          * Virtual GoDown Method
          * Moves the robot down in the maze
          * @param x x coordinate of the robot
          * @param y y coordinate of the robot
          */
        virtual void GoDown(int x, int y)= 0; //-- pure virtual method
        /**
          * Virtual TurnLeft Method
          * Moves the robot left in the maze
          * @param x x coordinate of the robot
          * @param y y coordinate of the robot
          */
        virtual void TurnLeft(int x, int y)= 0; //-- pure virtual method
        /**
          * Virtual TurnRight Method
          * Moves the robot right in the maze
          * @param x x coordinate of the robot
          * @param y y coordinate of the robot
          */
        virtual void TurnRight(int x, int y)= 0; //-- pure virtual method
        /**
         * Virtual PickUp Method
         * Arm picks up an object
         * @param obj
         */
        virtual void PickUp(std::string obj);
        /**
         * Virtual Release Method
         * Arm release an object
         * @param obj
         */
        virtual void Release(std::string obj);
        /**
         * Get the x coordinate of the robot
         * @return
         */
        virtual int get_x() const {
            return x_;
        };
        /**
        * Get the y coordinate of the robot
        * @return
        */
        virtual int get_y() const {
            return y_;
        };

        /**< Destructor for LandBasedRobot*/
        virtual ~LandBasedRobot(){
            //std::cout << "Destructor for " << name_ << " called" << std::endl;
        };

    protected:
        const std::string name_; /**< Name of the robot */
        double speed_{}; /**< Driving speed of the robot */
        double width_{}; /**< Width of the base of the robot */
        double length_{}; /**< Width of the base of the robot */
        double height_{}; /**< Height of the base of the robot */
        double capacity_{}; /**< Height of the base of the robot */
        int x_; /**< x coordinate of the robot */
        int y_; /**< y coordinate of the robot */
    }; //--class LandBasedRobot
}//--namespace fp


#endif //MAIN_CPP_LANDBASEDROBOT_H
