#include <iostream>
#include <array>
#include <iterator>
#include <vector>


#define LOG(x) std::cout << x << std::endl;
#define LOG2(x,y) std::cout << x << y << std::endl;


/************************
Structure
************************/
struct Person {
    std::string name;
    int birth_year;
    int birth_month;
    int birth_day;
    double height;//--cm
    double weight;//--kg
};//-- do not forget the semi-colon


//--Non-static Member Initialization
//struct Person {
//    std::string name{"None"};
//    int birth_year{1970};
//    int birth_month{1};
//    int birth_day{1};
//    double height{100};//--cm
//    double weight{100};//--kg
//};//-- do not forget the semi-colon

void DisplayPerson(Person person){
    std::cout << "Name: " << person.name << std::endl;
    std::cout << "Birth year: " << person.birth_year << std::endl;
    std::cout << "Birth month: " << person.birth_month << std::endl;
    std::cout << "Birth day: " << person.birth_day << std::endl;
    std::cout << "Height: " << person.height << std::endl;
    std::cout << "Weight: " << person.weight << std::endl;
}

Person BuildRandomPerson(){
    return{"Person", 1950, 1, 1, 100, 100};
}

int main() {
//    Person person{BuildRandomPerson()};
//    DisplayPerson(person);

//    Person bjarne;
//    bjarne.name = "Bjarne Stroustrup";
//    bjarne.birth_year = 1950;
//    bjarne.birth_month = 12;
//    bjarne.birth_day = 30;
//    bjarne.height = 165;
//    bjarne.weight = 65;
//
//    Person bjarne{"Bjarne Stroustrup", 1950,
//                  12, 30, 165, 65};

//    Person guido;
//    guido.name = "Guido Van Rossum";
//    guido.birth_year = 1956;
//    guido.birth_month = 1;
//    guido.birth_day = 31;
//    guido.height = 172.72;
//    guido.weight = 75;
//    Person guido{"Guido van Rossum", 1956,
//                 1, 31, 172.72, 75};


//    //--who is younger?
//    if (bjarne.birth_year > guido.birth_year)
//        std::cout << bjarne.name << " is younger than "
//                  << guido.name << std::endl;
//    else if (bjarne.birth_year < guido.birth_year)
//        std::cout << guido.name << " is younger than "
//                  << bjarne.name << std::endl;
//
//    //--total height of both persons
//    double total_height = bjarne.height + guido.height;
//
//
//    //--bjarne lost weight
//    bjarne.weight -= 2;
}



/************************
Enumeration
************************/
////--Define a new enumeration named ColorRedShade
//enum ColorRedShade{
//    kBurgundy,
//    kCrimsonRed,
//    kRaspberry,//trailing comma on the last enumerator is possible since C++ 11
//}; //--The enum itself must end with a semicolon
//
////enum Fruit{
////    kBanana,
////    kApple,
////    kRaspberry,//trailing comma on the last enumerator is possible since C++ 11
////}; //--The enum itself must end with a semicolon
//
//
//int main() {
////--Define a few variables of enumerated type Color
//    ColorRedShade house(kBurgundy);
//    ColorRedShade apple{kCrimsonRed};
//    ColorRedShade car{kRaspberry};
//    return 0;
//}



/************************
Arrays
************************/

//int main(){
////    int array_1[5]{};//--Can hold 5 elements
////    LOG(array_1[0])
////    LOG(array_1[1])
////    LOG(array_1[2])
////
////    const int array_length{3};//--Using a constant
////    int array_2[array_length]{};//--Can hold 3 elements
////
//////--With enumerator
////    enum ArrayElements{
////        max_array_length = 4
////    };
////    int array_3[max_array_length];//--Can hold 4 elements
////
////#define ARRAY_LENGTH 5//--Macro
////    int array_4[ARRAY_LENGTH]{}; //--Syntactically correct but should be avoided
//
//    //--With struct
////    struct Person{
////        std::string name;
////        int age;
////    };
////
////    Person  array_person[]{
////        {"John", 32},
////        {"Jane", 34}
////    };
////
////    LOG(array_person[0].name)
////    LOG(array_person[0].age)
////    LOG("--------------")
////    LOG(array_person[1].name)
////    LOG(array_person[1].age)
//
///**
// * C-style Initialization
// */
////    int array_1[]{1, 2, 3, 5, 6};//--individual element
////    //--size of a C-style array
////    std::cout << std::size(array_1) << std::endl;
//
///**
// * C++-style initialization
// */
////    std::array<int, 3> array_1{{1, 2, 3}};//--each element
//
////    std::array<int, 3> array_2 = {1,2, 3};
////    std::array<int, 3> array_2={1};//--partial initialization
////    array_1.fill(4);
////    LOG(array_1[0])
////    LOG(array_1[1])
////    LOG(array_1[2])
//
////    std::cout << array_1.size() << std::endl;
//
///**
// * Access
// */
////    std::cout << array_1[0] << std::endl;//--1
////    std::cout << array_1[1] << std::endl;//--2
////    std::cout << array_1[2] << std::endl;//--3
////    std::cout << array_1[3] << std::endl;//--??
////    LOG(array_1[3])
////    std::cout << array_1.at(0) << std::endl;//--1
////    std::cout << array_1.at(1) << std::endl;//--2
////    std::cout << array_1.at(2) << std::endl;//--3
////    std::cout << array_1.at(3) << std::endl;//--error
///**
// * Modification
// */
////    array_1[0] = -1;
////    array_1[1] = -2;
////    array_1[2] = -3;
////    array_1[3] = -4;//--??
////
////    array_1.at(0) = -5;
////    array_1.at(1) = -6;
////    array_1.at(2) = -7;
////    array_1.at(3) = -8;//--error
//}


/************************
Vectors
************************/
//int main(){

//int num{};
//std::cout << "Please enter a number: ";
//std::cin >> num;
//std::array<int, num> array_1{};

////    int n{3};
////    std::vector<int> vector_1(n,1);
//
//
////    std::vector<std::string> peg_colors{"orange","yellow","red"};
////
////    std::cout << "1st peg: " << peg_colors[0] << std::endl;
////    std::cout << "2nd peg: " << peg_colors[1] << std::endl;
////    std::cout << "3rd peg: " << peg_colors[2] << std::endl;
////
////    std::cout << "1st peg: " << peg_colors.at(0) << std::endl;
////    std::cout << "2nd peg: " << peg_colors.at(1) << std::endl;
////    std::cout << "3rd peg: " << peg_colors.at(2) << std::endl;
////
////
////    std::vector<std::string> alpha_vector{"a","b","c","d","e"};
////    LOG(alpha_vector.size())
////    LOG(alpha_vector.at(0))
////    LOG(alpha_vector.at(1))
////    LOG(alpha_vector.at(2))
////    LOG(alpha_vector.at(3))
////    LOG(alpha_vector.at(4))
////    //--remove the third element
////    alpha_vector.erase(alpha_vector.begin()+2);
////    LOG("-------------------------")
////    LOG(alpha_vector.size())
////
////    LOG(alpha_vector.at(0))
////    LOG(alpha_vector.at(1))
////    LOG(alpha_vector.at(2))
////    LOG(alpha_vector.at(3))
////    LOG(alpha_vector.at(4))
//}

//int main(){
//    int array_1[]{1, 2, 3};
//    LOG(std::size(array_1))
//    std::array<int, 3> array_2 {};//--partial initialization
//    array_2.fill(6);
//    LOG(array_2.at(1))
//}
