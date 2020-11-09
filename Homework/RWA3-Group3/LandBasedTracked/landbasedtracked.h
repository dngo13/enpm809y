#ifndef MAIN_CPP_LANDBASEDTRACKED_H
#define MAIN_CPP_LANDBASEDTRACKED_H

#include <iostream>
#include <memory>
#include "../LandBasedRobot/LandBasedRobot.h"

namespace rwa3 {

    class LandBasedTracked : public LandBasedRobot {
    public:
        /**
         * LandBasedTracked Constructor
         * @param name name of the robot
         * @param x x coordinate of the robot
         * @param y y coordinate of the robot
         */
        explicit LandBasedTracked(std::string name="tracked", int x=2, int y=3):
            //name_{name}, x_{x}, y_{y}{
            LandBasedRobot(name, x, y), track_type{} {
            //std::cout << "Constructor for " << name_ <<  " called" << std::endl;
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
        /**< Destructor for LandBasedTracked*/
        virtual ~LandBasedTracked(){
        //    std::cout << "Destructor for " << name_ << " called" << std::endl;
        };

    protected:
        std::shared_ptr<std::string> track_type; /** Type of track mounted on the robot */
        const std::string name_; /**< Name of the robot */
        double speed_{}; /**< Driving speed of the robot */
        double width_{}; /**< Width of the base of the robot */
        double length_{}; /**< Width of the base of the robot */
        double height_{}; /**< Height of the base of the robot */
        double capacity_{}; /**< Height of the base of the robot */
        int x_; /**< x coordinate of the robot */
        int y_; /**< y coordinate of the robot */
    };//--class LandBasedTracked

}//--namespace rwa3

#endif //MAIN_CPP_LANDBASEDTRACKED_H
