/** \file file.h
 * Code for Lecture04 on Functions
 * Code can be found from slides
 */

#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
//#include "Eigen/Core"
#define LOG(x) std::cout << x << std::endl;


int main(){
    std::cout << sqrt(25) << std::endl;
    double result = pow(3.0,4.0);
    std::cout << result << std::endl;
}

//int main() {
//    int rows=5, cols=5;
//    Eigen::MatrixXf m(rows,cols);
//    m << (Eigen::Matrix3f() << 1, 2, 3, 4, 5, 6, 7, 8, 9).finished(),
//            Eigen::MatrixXf::Zero(3,cols-3),
//            Eigen::MatrixXf::Zero(rows-3,3),
//            Eigen::MatrixXf::Identity(rows-3,cols-3);
//    std::cout << m;
//}


///**
//* @brief Adds two integer numbers and returns the result.
//* @param a an integer argument.
//* @param b an integer argument.
//* @return The result of  \p a + \p b.
//*/
//int AddNumbers(int a, int b){
//    std::cout << a << " + " << b << " = "<< a+b << std::endl;
//    return a + b;
//}
//
//int main(){
//    int x = AddNumbers(2,3);
//    int y = AddNumbers(4,6);
//    AddNumbers(x,y);
//}


/**
 * Return Statement
*/
//void PrintLargerNumber(int num1, int num2){
//    if (num1 > num2)
//        std::cout << num1 << std::endl;
//    else if (num1 < num2)
//        std::cout << num2 << std::endl;
//    else std::cout << "Equal" << std::endl;
//    return;//--Optional
//}
//
////void PrintLargerNumber2(int num1, int num2){
////    if (num1 > num2)
////        std::cout << num1 << std::endl;
////    if (num1 < num2)
////        std::cout << num2 << std::endl;
////    if (num1==num2)
////        std::cout << "Equal" << std::endl;
////}
////
//int main(){
////    PrintLargerNumber(45,3);
//    PrintLargerNumber2(45,3);
//}

/**
 * main Function Arguments
*/
//int MultiplyNumbers(int, int);//--Function prototype
//
//int MultiplyNumbers(int a, int b){
//    return a * b;
//}
//
//int main(int argc, char** argv) {
//     std::cout << "Have " << argc << " arguments:" << std::endl;
//     for (int i = 0; i < argc; ++i) {
//         std::cout << argv[i] << std::endl;
//     }
//
////    std::cout << "Please enter two integers separated by a space: ";
////    int x{}, y{};
////    std::cin >> x >> y;
////    std::cout << MultiplyNumbers(x, y) << std::endl;
////
////    std::istringstream x_iss(argv[1]);
////    std::istringstream y_iss(argv[2]);
////    if (x_iss >> x){
////        if (y_iss >> y){
////            std::cout << MultiplyNumbers(x, y) << std::endl;
////        }
////    }
//}


/**
 * PASS BY VALUE
*/
//void AddOne(int number);
//int MultiplyNumbers(int num1, int num2);
//
//int main(){
//    int num1{1}, num2{5};
//    std::cout << num1 << std::endl;
//    std::cout << &num1 << std::endl;
//    AddOne(num1);
//    std::cout << num1 << std::endl;
//    int result = MultiplyNumbers(num1, num2);
//    LOG(result)
//}
//
//void AddOne(int num1){
//    std::cout << &num1 << std::endl;
//    num1++;
//}
//
////int MultiplyNumbers(int a, int b){
////    return a*b;
////}


/**
 * PASS BY REFERENCE
*/
//void AddOne(int& number);
//
//int main(){
//    int num1{1};
//    std::cout << num1 << std::endl;
//    std::cout << &num1 << std::endl;
//    AddOne(num1);
//    std::cout << num1 << std::endl;
//}
//
//void AddOne(int& num1){
//    std::cout << &num1 << std::endl;
//    num1++;
//}
/**
 * ----------------------
*/
//void SwapNumbers(int& a, int& b);
//
//int main(){
//    int num1{5};
//    int num2{100};
//    std::cout << num1 <<','<< num2 << std::endl;
//    SwapNumbers(num1, num2);
//    std::cout << num1 <<','<< num2 << std::endl;
//}
//
//void SwapNumbers(int& a, int& b){
//    int tmp{a};
//    a = b;
//    b = tmp;
//}
/**
 * ----------------------
*/
//void PrintVector(const std::vector<int> vect){
//    for (auto value: vect) {
//        std::cout << value << ' ';
//    }
//    std::cout << std::endl;
//}
//
//void ZeroVector(std::vector<int> vect){
//    for (auto value: vect)
//        value = 0;
//    PrintVector(vect);
//}
//
//int main(){
//    std::vector<int> my_vector{1,2,3,4,5};
//    ZeroVector(my_vector);
//    PrintVector(my_vector);
////    LOG(sizeof(my_vector));
//}


/**
 * ----------------------
*/
//struct Person {
//    std::string name;
//    int birth_year;
//    int birth_month;
//    int birth_day;
//    double height;//--cm
//    double weight;//--kg
//};//-- do not forget the semi-colon

//void DisplayPerson(const Person person){
//    std::cout << "Name: " << person.name << std::endl;
//    std::cout << "Birth year: " << person.birth_year << std::endl;
//    std::cout << "Birth month: " << person.birth_month << std::endl;
//    std::cout << "Birth day: " << person.birth_day << std::endl;
//    std::cout << "Height: " << person.height << std::endl;
//    std::cout << "Weight: " << person.weight << std::endl;
//
//}
//
//int main(){
//    Person bjarne;
//    LOG(sizeof(bjarne));
//    bjarne.name = "Bjarne Stroustrup";
//    bjarne.birth_year = 1950;
//    bjarne.birth_month = 12;
//    bjarne.birth_day = 30;
//    bjarne.height = 165;
//    bjarne.weight = 65;
//    DisplayPerson(bjarne);
//}

/**
 * DEFAULT ARGUMENTS
*/
//void AddNumbers(int,int=4,int=5);//-- prototype
//void AddNumbers(int a,int b=4,int c=5){
//    std::cout << a + b + c << std::endl;
//}
//
//int main(){
//    AddNumbers(1);
//    AddNumbers(1,2);
//    AddNumbers();
//}

/**
 * FUNCTION OVERLOADING
*/
//int Multiply(int i, int j) {return i*j;}
//double Multiply(double i, double j) {return i*j;}
//double Multiply(double i, double j, double k) {return i*j*k;}
//
//int main(){
//    Multiply(1,2); //--Multiply(int,int)
//    Multiply(1.5,2.5);//--Multiply(double,double)
//    Multiply(1.5,2.5, 3.5);//--Multiply(double,double, double)
//}

/**
 * -- With default arguments
*/
//int Multiply(int i) {return i*3;}
//double Multiply(double i=2, double j=3) {return i*j;}
//int main(){
//    Multiply();
//    Multiply(4);
//    Multiply(2.5, 3.5);
//}


//double Multiply(double i=2, double j=3) {return i*j;}
//
//int Multiply(int i) {return i*2;}
//int Multiply(int i, int j=2) {return i*j;}
//int main(){
//    Multiply();
//    Multiply(10);//--ambiguous
//}

/**
 * 1. A match is found
*/
//int Multiply(int i, int j) {return i*j;}
//double Multiply(double i, double j) {return i*j;}
//
//int main(){
//    int i{2}, j{3};
//    LOG(Multiply(i,j)); //--Multiply(int,int)
//}

/**
 * 2. A match is not found: promotion
*/
//int Multiply(int i, int j) {return i*j;}
//
//int main(){
//    short i{2}, j{3};
//    LOG(Multiply(i,j)); //--i and j promoted to int
//}

/**
 * 3. No promotion possible: standard conversion
*/
//int Multiply(int i, int j) {return i*j;}
//
//int main(){
//    double i{2.6}, j{3.3};
//    //--No match for Multiply(double, double)
//    //-- i and j are converted to int
//    LOG(Multiply(i,j));
//}

/**
 * 4. What is happening here?
*/
//double Multiply(double i, int j) {return i*j;}
//
//int main(){
//    int i{3};
//    double j{3.3};
//    //--No match for Multiply(double, double)
//    //-- i and j are converted to int
//    LOG(Multiply(i,j));
//}

/**
 * STATIC VARIABLES
*/
//void StaticLocalExample();
//
//int main(){
//    for (int i{0}; i<10; i++){
//        StaticLocalExample();
//    }
//}
//
//void StaticLocalExample(){
//    int num {10};
//    std::cout << "num is: " << num << std::endl;
//    num ++;
//}

/**
 * RECURSIVE FUNCTIONS
*/
//unsigned long long Factorial(unsigned long long n){
//    if (n == 0)
//        return 1;
//    return n*Factorial(n-1);
//}
//
//unsigned long long Fibo(unsigned long long n){
//    if (n <=1)
//        return n;
//    return Fibo(n-1) + Fibo(n-2);
//}
//
//int main(){
////   std::cout << Fibo(8) << std::endl;
//    std::cout << Factorial(3) << std::endl;
//}