// Main file from lecture video, Left wall follow algorithm shown in lecture video (direct calls to API)
#include <iostream>
#include "API/api.h"

struct Position {
    int x;
    int y;
} position;

void log(const std::string& text) {
    std::cerr << text << std::endl;
}

void UpdateDirection(char& current_direction, const char turn) {
    log("Turning " + std::string(1,turn));

    if (current_direction == 'N') {
        if (turn == 'l')
            current_direction = 'W';
        else
            current_direction = 'E';
    }
    else if (current_direction == 'E') {
        if (turn == 'l')
            current_direction = 'N';
        else
            current_direction = 'S';
    }
    else if (current_direction == 'S') {
        if (turn == 'l')
            current_direction = 'E';
        else
            current_direction = 'W';
    }
    else if (current_direction == 'W') {
        if (turn == 'l')
            current_direction = 'S';
        else
            current_direction = 'N';
    }
    log("direction: " + std::string(1,current_direction));

}

void UpdatePosition(const char current_direction, const char move, Position& position) {
    if (current_direction == 'N')
        if (move == 'f')
            position.y ++;

    if (current_direction == 'E')
        if (move == 'f')
            position.x ++;

    if (current_direction == 'S')
        if (move == 'f')
            position.y --;

    if (current_direction == 'W')
        if (move == 'f')
            position.x --;
}

int main(int argc, char* argv[]) {
    char direction{'N'};
    position.x = 0;
    position.y = 0;

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
        UpdatePosition(direction, 'f', position);
        log(std::to_string(position.x));
        log(std::to_string(position.y));
        log("--------------");

        if (direction == 'N') {
            if (fp::API::wallLeft()) {fp::API::setWall(position.x, position.y, 'w');}
            if (fp::API::wallRight()) {fp::API::setWall(position.x, position.y, 'e');}
            if (fp::API::wallFront()) {fp::API::setWall(position.x, position.y, 'n');}
        }

        if (direction == 'E') {
            if (fp::API::wallLeft()) {fp::API::setWall(position.x, position.y, 'n');}
            if (fp::API::wallRight()) {fp::API::setWall(position.x, position.y, 's');}
            if (fp::API::wallFront()) {fp::API::setWall(position.x, position.y, 'e');}
        }

        if (direction == 'S') {
            if (fp::API::wallLeft()) {fp::API::setWall(position.x, position.y, 'e');}
            if (fp::API::wallRight()) {fp::API::setWall(position.x, position.y, 'w');}
            if (fp::API::wallFront()) {fp::API::setWall(position.x, position.y, 's');}
        }

        if (direction == 'W') {
            if (fp::API::wallLeft()) {fp::API::setWall(position.x, position.y, 's');}
            if (fp::API::wallRight()) {fp::API::setWall(position.x, position.y, 'n');}
            if (fp::API::wallFront()) {fp::API::setWall(position.x, position.y, 'w');}
        }

    }
}