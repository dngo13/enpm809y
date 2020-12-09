#include <iostream>
#include <vector>
#include "Villain/villain.h"


void PrintVillain(game::Villain villain){
    std::cout << villain << std::endl;
}
//
//game::Villain CreateFinalBoss(){
//    game::Villain lucifer{"Lucifer", 1000, 1, 100};
//    return lucifer;
//}

void TakeVillain(game::Villain villain){
//    std::cout << villain.life_ << std::endl;
}

void Square(int& x){

}

void Square(int&& x){

}

int main(){
    game::Villain firebrand;
    firebrand = game::Villain{"Firebrand", 200, 3, 100};
//    game::Villain firebrand_copy{"Firebrand2", 300, 5};
//    std::cout << firebrand << std::endl;
//    std::cout << firebrand_copy << std::endl;
//    firebrand_copy = firebrand;
//    std::cout << firebrand_copy << std::endl;

std::vector<game::Villain> vect;
vect.push_back(game::Villain{"Firebrand", 200, 3});



//    game::Villain firebrand;
//    firebrand = game::Villain{"Firebrand", 200, 3, 100};
}