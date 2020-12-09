#include <iostream>
#include <vector>
#include "Villain/villain.h"


//void PrintVillain(game::Villain firebrand){
//    std::cout << firebrand << std::endl;
//
//}
//
//game::Villain CreateFinalBoss(){
//    game::Villain lucifer{"Lucifer", 1000, 1, 100};
//    return lucifer;
//}

void TakeVillain(game::Villain villain){
    std::cout << villain.life_ << std::endl;
}

int main(){
    game::Villain firebrand{"Firebrand", 100, 2};

    //    for (auto i{0}; i<10; i++){
//        firebrand.TakeDamage(25);
//    }


//    game::Villain firebrand;
//    firebrand = game::Villain{"Firebrand", 200, 3, 100};
}