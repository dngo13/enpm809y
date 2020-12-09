
#include "src/LandBasedWheeled/landbasedwheeled.h"
#include "src/LandBasedTracked/landbasedtracked.h"
#include <iostream>
#include <string>
#include "API/api.h"

void log(const std::string& text) {
    std::cerr << text << std::endl;
}

void UpdateDirection(char current_direction, const char turn){
    log( "Turning " + std::string(1,turn));
    if (current_direction=='N') {
        if (turn== 'l')
            current_direction = 'W';
        else
            current_direction = 'E';
    }
    else if (current_direction=='E') {
        if (turn== 'l')
            current_direction = 'N';
        else
            current_direction = 'S';
    }
    else if (current_direction=='S') {
        if (turn== 'l')
            current_direction = 'E';
        else
            current_direction = 'W';
    }
    else if (current_direction=='W') {
        if (turn== 'l')
            current_direction = 'S';
        else
            current_direction = 'N';
    }
    log(  std::string(1,current_direction));
}

int main(){
    char direction{'N'};
    std::cout<< "Main started" << std::endl;
    log("Starting...");
    fp::API::setColor(0, 0, 'r');
    fp::API::setText(0, 0, "S");
    fp::API::setText(7, 7, "G");
    fp::API::setText(7, 8, "G");
    fp::API::setText(8, 7, "G");
    fp::API::setText(8, 8, "G");

    while (true) {
        if (!fp::API::wallLeft()) {
            fp::API::turnLeft();
            UpdateDirection(direction, 'l');
        }
        while (fp::API::wallFront()) {
            fp::API::turnRight();
            UpdateDirection(direction, 'r');
        }
        fp::API::moveForward();
    }
    return 0;
}