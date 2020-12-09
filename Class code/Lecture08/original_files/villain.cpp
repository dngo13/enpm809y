//
// Created by zeid on 10/15/20.
//

#include "villain.h"

namespace game {
    void Villain::TakeDamage(double damage) {
        if (!IsDead()) {
            health_ -= damage;
            std::cout << name_ << "'s health: " << health_ << std::endl;
        } else {
            std::cout << name_ << " is dead!!" << std::endl;
        }
    }

    bool Villain::IsDead() {
        if (health_ <= 0) {
            if (life_ > 1) {
                life_--;
                health_ = original_health_;
                std::cout << name_ << " has " << life_ << " life(ves) left." << std::endl;
                return false;
            } else return true;
        }
    }

//    std::ostream &operator << (std::ostream &out, const Villain& villain){
//        out << "Name: " << villain.name_
//        << ", Health: " << villain.health_
//        << ", Life: " << villain.life_;
//        return out;
//    }
//
//    std::istream &operator >> (std::istream &in,  Villain &villain){
//        std::cout << "Enter name: ";
//        in >> villain.name_;
//        std::cout << "Enter health points: ";
//        in >> villain.health_;
//        std::cout << "Enter number of lives: ";
//        in >> villain.life_;
//        return in;
//    }

//    void Print(const Villain& villain){
//        std::cout << "Name: " << villain.name_
//        << ", Health: " << villain.health_
//        << ", Life: " << villain.life_
//        << ", Strength: " << *villain.strength_;
//    }
//
//    void Display::PrintName(const Villain& villain){
//        std::cout << "Name: " << villain.name_ << std::endl;
//    }
//
//    void Display::PrintHealth(const Villain& villain){
//        std::cout << "Health: " << villain.health_ << std::endl;
//    }
}//--namespace game



