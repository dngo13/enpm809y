//
// Created by zeid on 10/15/20.
//

#ifndef LECTURE8_VILLAIN_H
#define LECTURE8_VILLAIN_H

#include <iostream>
#include <utility>

namespace game {
    class Villain;//--forward declaration

    class Display{
    public:
        void PrintName(const Villain& villain);
        void PrintHealth(const Villain& villain);
    };//--class Display

    class Villain {
    public:
        explicit Villain(std::string name="Villain", double health=100, int life=1, int strength=10):
                name_{name},
                health_{health},
                life_{life},
                original_health_{health_},
                strength_ptr_{nullptr}{
            std::cout << "Constructor called for " << name_  << std::endl;
            strength_ptr_ = new int;
            *strength_ptr_ = strength;
        }



//        explicit Villain(std::string name="Villain", double health=100, int life=1):
//                name_{name},
//                health_{health},
//                life_{life},
//                original_health_{health_}{
//            std::cout << "Constructor called for " << name_  << std::endl;
//        }

        //shallow copy constructor
//        Villain(const Villain& source):
//                name_{source.name_},
//                health_{source.health_},
//                life_{source.life_},
//                original_health_{source.health_},
//                strength_ptr_{source.strength_ptr_}{
//            std::cout << "Shallow copy constructor called for " << name_  << std::endl;
//        }

        //--deep copy constructor
        Villain(const Villain& source):
                name_{source.name_},
                health_{source.health_},
                life_{source.life_},
                original_health_{source.health_}, strength_ptr_{nullptr}{
            std::cout << "Deep copy constructor called for " << name_  << std::endl;
            strength_ptr_ = new int;
            *strength_ptr_ = *source.strength_ptr_;
        }

        //--Move constructor
        Villain(Villain&& source) noexcept:
                name_{source.name_},
                health_{source.health_},
                life_{source.life_},
                original_health_{source.health_}, strength_ptr_{nullptr}{
            std::cout << "Move constructor called for " << name_  << std::endl;
            strength_ptr_ = source.strength_ptr_;
            source.strength_ptr_ = nullptr;
        }

        //--copy assignment operator performing shallow copy
//        Villain& operator= (const Villain& rhs){
//            std::cout << "Shallow copy assignment operator called..." << std::endl;
//            if (this == &rhs){ return *this; } //make sure you aren't self-assigning
//
//            //same as copy constructor from here
//            name_ = rhs.name_;
//            health_ = rhs.health_;
//            life_ = rhs.life_;
//            original_health_ = rhs.original_health_;
//            strength_ptr_ = rhs.strength_ptr_;
//            return *this;
//        }

        //--copy assignment operator performing deep copy
        Villain& operator= (const Villain& rhs){
            std::cout << "Deep copy assignment operator called..." << std::endl;
            if (this == &rhs){
                return *this;
            } //make sure you aren't self-assigning

            //same as copy constructor from here
            name_ = rhs.name_;
            health_ = rhs.health_;
            life_ = rhs.life_;
            original_health_ = rhs.original_health_;
            delete strength_ptr_; // get rid of the old data
            strength_ptr_ = new int;
            *strength_ptr_ = *rhs.strength_ptr_;
            return *this;
        }

        //--move assignment operator performing deep copy
        Villain& operator= (Villain&& rhs) noexcept {
            std::cout << "Move assignment operator called..." << std::endl;
            if (this == &rhs){ return *this; } //make sure you aren't self-assigning
            name_ = rhs.name_;
            health_ = rhs.health_;
            life_ = rhs.life_;
            original_health_ = rhs.original_health_;
            delete strength_ptr_; // get rid of the old data
            strength_ptr_ = rhs.strength_ptr_;
            rhs.strength_ptr_ = nullptr;
            return *this;
        }

        ~Villain(){
            std::cout << "Destructor called for " << name_ << std::endl;
            delete strength_ptr_;
        }

        void TakeDamage(double damage);
        bool IsDead();


        //--friends
        friend std::ostream &operator << (std::ostream &output, const game::Villain& villain);
        friend std::istream &operator >> (std::istream &in,  game::Villain &villain);
        friend void Print(const Villain& villain);
//        friend void Display::PrintName(const Villain& villain);
        friend class Display;

    private:
        int life_;
        std::string name_;
        double health_;
        double original_health_;
        int *strength_ptr_;

    };//--class Villain
}//--namespace game



#endif //LECTURE7_VILLAIN_H
