#include <iostream>
#include <vector>
#include "Villain/villain.h"
#include "Werewolf/werewolf.h"
#include "Vampire/vampire.h"

/class Base{
//public:
//    explicit Base(int b=0):
//            b_{b}{
//        std::cout << "Constructor called for Base" << std::endl;
//    }
//    ~Base(){
//        std::cout << "Destructor called for Base" << std::endl;
//    }
//protected:
//    int b_;
//};//--class Base
//
//class Derived: public Base{
//public:
//    explicit Derived(double d=0.0):
//            d_{d}{
//        std::cout << "Constructor called for Derived" << std::endl;
//    }
//    ~Derived(){
//        std::cout << "Destructor called for Derived" << std::endl;
//    }
//protected:
//    double d_;
//};//--class Derived

int main(){
//    game::Villain firebrand{"Firebrand", 200, 3, 100};
    game::Vampire vlad;
    game::Werewolf wolf;
}