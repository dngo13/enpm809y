#include<iostream>

//-- Variables
int main(){
    int age{};
    std::string name{};
    std::cout << "Please enter your age and your name: " << std::endl;
    std::cin >> age >> name;
    std::cout << "Your age is : " << age << std::endl;
    std:: cout << "Your name is: " << name << std::endl;
}
 ///int a = 1.54;
//  int b (1.54);
//    int c {1};
//    bool d = false;
////    std::cout << a << std::endl;
////    std::cout << b << std::endl;
////    std::cout << c << std::endl;
////    std::cout << d << std::endl;
//
//    std::cout << sizeof(int) << std::endl;
//    std::cout << sizeof(double) << std::endl;
//    std::cout << sizeof(float) << std::endl;
//    std::cout << sizeof(std::string) << std::endl;
//    std::cout << sizeof(char) << std::endl;
//}



//#include<iostream>
//
//#define LENGTH 10
//#define WIDTH  5
//#define NEWLINE '\n'
//#define LOG(x)  std::cout << x;
//
//int main() {
//    int area;
//
//    area = LENGTH * WIDTH;
//    LOG(area)
//    std::cout << NEWLINE;
//    return 0;
//}

//#include <iostream>
//
//#define OPEN_CURLY {
//
//
//int main()OPEN_CURLY
//    std::cout << "Hello World" << std::endl;
//    return 0;
//}


//-- undefine and redefine
//#include <iostream>
//
//#define LENGTH 10
//#define LOG(x) std::cout << x;
//
//int main(){
//    std::cout << LENGTH << std::endl; //-- 10
//    {//--creating a new scope
//#undef LENGTH
//#undef LOG
//#define LENGTH 200
//
//        std::cout << LENGTH << std::endl; //-- 200
//    }
//    std::cout << LENGTH << std::endl; //-- 200
//    return 0;
//}



