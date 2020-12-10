#ifndef MAIN_CPP_LANDBASEDROBOT_H
#define MAIN_CPP_LANDBASEDROBOT_H
/**< LandBasedRobot.h , Base abstract class*/
#include <string>
#include <iostream>
//#include <utility>

namespace fp {
    class LandBasedRobot { //--abstract class
     public:
        /**
         * Accessor function for speed
         * @return speed_
         */
        double get_speed() const {
            return speed_;
        }
        double speed = get_speed();
        /**
         * Accessor function for width
         * @return width_
         */
        double get_width() const {
            return width_;
        }
        double width = get_width();
        /**
         * Accessor function for length
         * @return length_
         */
        double get_length() const {
            return length_;
        }
        double length = get_length();
        /**
         * Accessor function for height
         * @return height_
         */
        double get_height() const {
            return height_;
        }
        double height = get_height();
        /**
         * Accessor function for capacity
         * @return
         */
        double get_capacity() const {
            return capacity_;
        }
        double capacity = get_capacity();
        //**********************************//
        /**
         * Mutator (setter) function for speed
         * @param speed
         * @return Returns nothing
         */
        double set_speed(double speed) {
            speed_ = speed;
        }

      /**
       * LandBasedRobot Constructor
       * @param name name of the robot
       * @param x x coordinate of the robot
       * @param y y coordinate of the robot
       * @param direction direction that the robot is facing in the maze
       */
        explicit LandBasedRobot(std::string name="robot", int x=0, int y=0, char direction='N') :
            name_{std::move(name)}, x_{x}, y_{y}, direction_{direction}, speed_{speed},width_{width},
            length_{length}, height_{height}, capacity_{capacity} {
            //std::cout << "Constructor for " << name_ << " called" << std::endl;
            }
        /**
          * Virtual GetDirection Method
          * Get the direction of the robot in the maze
          * @param x x coordinate of the robot
          * @param y y coordinate of the robot
         */
        virtual char GetDirection()= 0; //-- pure virtual method
        /**
          * Virtual MoveForward Method
          * Moves the robot forward in the maze
          * @param x x coordinate of the robot
          * @param y y coordinate of the robot
        */
        virtual void MoveForward(int x, int y)= 0; //-- pure virtual method
        /**
           * TurnLeft Method
           * Rotate the the robot 90 degrees counter-clockwise
           * @param x x coordinate of the robot
           * @param y y coordinate of the robot
           */
        virtual void TurnLeft(int x, int y)= 0; //-- pure virtual method
        /**
          * TurnRight Method
          * Rotate the the robot 90 degrees clockwise
          * @param x x coordinate of the robot
          * @param y y coordinate of the robot
          */
        virtual void TurnRight(int x, int y)= 0; //-- pure virtual method


        /**< Destructor for LandBasedRobot*/
        virtual ~LandBasedRobot(){
            //std::cout << "Destructor for " << name_ << " called" << std::endl;
        };

    protected:
        /**< Attributes */
        const std::string name_; /**< Name of the robot */
        double speed_{}; /**< Driving speed of the robot */
        double width_{}; /**< Width of the base of the robot */
        double length_{}; /**< Width of the base of the robot */
        double height_{}; /**< Height of the base of the robot */
        double capacity_{}; /**< Height of the base of the robot */
        int x_; /**< x coordinate of the robot */
        int y_; /**< y coordinate of the robot */
        char direction_{'N'}; /**< Direction that the robot is facing in the maze*/
    }; //--class LandBasedRobot
}//--namespace fp


#endif //MAIN_CPP_LANDBASEDROBOT_H
