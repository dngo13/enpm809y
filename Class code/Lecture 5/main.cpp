#include <iostream>
#include <typeinfo>
#include <array>
#include <vector>

//int main() {
//int *ptr{nullptr};
//    {
//        int x{3};
//        ptr = &x;
//    }
//
////    std::cout << typeid(x).name() << std::endl;
//    std::cout << *ptr << std::endl;
//
//    return 0;
//}


//int main(){
//    int a{1};
//    std::cout << a << std::endl;
//    std::cout << &a << std::endl;
//    std::cout << *(&a) << std::endl;
//}

//int main(){
//    char c{'a'};
//    char *my_pointer{&c};
//}

//int main(){
//    int a{};
//    int *ptr;
//    std::cout << ptr << std::endl;
//    ptr = &a;
//    std::cout << ptr << std::endl;
//
////    std::cout << typeid(&a).name() << '\n';
//}

//int main(){
//    int x{1};
//    int *p{&x};
//    std::cout << &x << std::endl; //--0x7ffe760cef0c
//    std::cout << p << std::endl; //--0x7ffe760cef0c
//    std::cout << typeid(&x).name() << std::endl;//--Pi
//    std::cout << typeid(p).name() << std::endl;//--Pi
//}

//--Typed pointers
//int main() {
//    int a{5};
//    double b{2.0};
//    int *ptr{nullptr};
//    ptr = &a;
//    ptr = &b;
//}


//int main() {
//    int a{5};
//    std::cout << &a; //--address of a
//    std::cout << a; //--value of a
//    int *ptr{&a}; //--points to a (holds the address of a)
//    std::cout << ptr << std::endl;; //--address held in ptr, which is &a
//    std::cout << *ptr << std::endl;; //--value that ptr is pointing to
//}

//--Dereferencing
//int main() {
//    int a{5};
//    std::cout << a << std::endl; //--5
//    int *ptr{&a};
//    std::cout << *ptr << std::endl; //--5 (value of a)
//    *ptr = 10;
//    std::cout << a << std::endl; //--10
//    std::cout << *ptr << std::endl; //--10
//}

//--Size of pointers
//int main() {
//    int a{5};
//    double b{5.0};
//    std::vector<double> c{};
//    std::vector<std::vector<double>> d{};
//
//    int *a_ptr{&a};
//    double *b_ptr{&b};
//    std::vector<double> *c_ptr{&c};
//    std::vector<std::vector<double>> *d_ptr{&d};
//
//    std::cout << "size of a_ptr: " << sizeof a_ptr << std::endl;
//    std::cout << "size of b_ptr: " << sizeof b_ptr << std::endl;
//    std::cout << "size of c_ptr: " << sizeof c_ptr << std::endl;
//    std::cout << "size of d_ptr: " << sizeof d_ptr << std::endl;
//}

//--Dynamic memory allocation
//int main(){
//    std::cout << new int << std::endl;
//    int *ptr{new int};
//    int *my_ptr{new int{6}};
//}

//--Memory leak
//int main(){
//    int i{10};
//    int *ptr{new int{5}};
//    std::cout << ptr << std::endl;//--0x55972558fe70
//    std::cout << *ptr << std::endl;//--5
//    ptr = &i;//-- reassigning pointer, lose dynamic storage
//    std::cout << ptr << std::endl;//--0x7ffd936afe1c
//    std::cout << *ptr << std::endl;//--10
//}

//int main(){
//    std::cout << new int << std::endl;
//    int *ptr{new int};
//    int *my_ptr{new int{6}};
//}

//-- delete not newed
//int main(){
//    int x{};
//    int *ptr{&x};
//    delete ptr;
//}

//--dangling pointers
//int main(){
//    int *ptr{new int{5}};
//    std::cout << ptr << std::endl;
//    std::cout << *ptr << std::endl;
//    delete ptr;// return the memory to the operating system.  ptr is now a dangling pointer.
//    std::cout << ptr << std::endl;
//    std::cout << *ptr << std::endl;//--Dereferencing a dangling pointer will cause undefined behavior
//    delete ptr;//--trying to deallocate the memory again will also lead to undefined behavior.
//}

//int main(){
//    int *ptr{new int{5}};
//    int *ptr2{ptr};
//    delete ptr;// return the memory to the operating system.  ptr is now a dangling pointer.
//    ptr = nullptr;
//    //--ptr2 is still a dangling pointer
//}

//--safe from dangling pointers
//int main(){
//    int x{};
//    int *ptr{new int{5}};
//    /*Do some work with the pointer*/
//    delete ptr;
//    ptr = &x;
//    *ptr = 3;
//    std::cout << x;
//}

//--Does the following program have a dangling pointer?
//int main(){
//    int *ptr{nullptr};
//    ptr = new int;
//    *ptr = 5;
//    ptr = nullptr;
//    delete ptr;
//}

//--Arrays
//int main(){
//    int *array_ptr{nullptr};
//    size_t size{};
//    std::cout << "How many entries in the array? ";
//    std::cin >> size;
//    //allocate that many integers contiguously on the heap
//    array_ptr = new int[size];
//    delete [] array_ptr;//--free allocated storage
//}

//--Determine if 2 pointers point to the same location
//int main() {
//    std::string s1{"Hello"};
//    std::string s2{"Hello"};
//
//    std::string *p1{&s1};
//    std::string *p2{&s2};
//    std::string *p3{&s1};
//
//    std::cout << (p1 == p2) << std::endl; //--false
//    std::cout << (p1 == p3) << std::endl; //--true
//}

//--Determine if 2 pointers point to the same data
//int main() {
//    std::string s1{"Hello"};
//    std::string s2{"Hello"};
//
//    std::string *p1{&s1};
//    std::string *p2{&s2};
//    std::string *p3{&s1};
//
//    std::cout << (*p1 == *p2) << std::endl; //--true
//    std::cout << (*p1 == *p3) << std::endl; //--true
//}

//--Pointers to constants
//int main() {
//    int highest_score {100};
//    int lowest_score {23};
//    const int *ptr {&highest_score};
//
//    *ptr = 90; //--error
//    ptr = &lowest_score; //--ok
//}

//--Constants Pointers
//int main() {
//    int highest_score {100};
//    int lowest_score {23};
//    int *const ptr {&highest_score};
//
//    *ptr = 90; //--ok
//    ptr = &lowest_score; //--error
//}

//--Constants Pointers to Constants
//int main() {
//    int highest_score {100};
//    int lowest_score {23};
//    const int *const ptr {&highest_score};
//
//    *ptr = 90; //--error
//    ptr = &lowest_score; //--error
//}

//--Pass pointer to function: Argument is a reference of a variable
//void DoubleValue(int *int_ptr);//--prototype
//void DoubleValue(int *int_ptr){
//    *int_ptr *= 2;
//}
//
//int main(){
//    int value{10};
//    std::cout << value << std::endl;//--10
//    DoubleValue(&value);
//    std::cout << value << std::endl;//--20
//    return 0;
//}


//--Pass pointer to function: Argument is a pointer
//void DoubleValue(int *int_ptr);//--prototype
//void DoubleValue(int *int_ptr){
//    *int_ptr *= 2;
//}
//
//int main(){
//    int value{10};
//    int *ptr{&value};
//    std::cout << value << std::endl;//--10
//    DoubleValue(ptr);
//    std::cout << value << std::endl;//--20
//    return 0;
//}

//--Returning pointers from functions

//--Safe
//int *LargestNumber (int *num1, int *num2){
//    if (*num1 > *num2)
//        return num1;
//    else
//        return num2;
//}
//
//int main(){
//    int a{100}, b{200};
//    int *largest_ptr{nullptr};
//    largest_ptr = LargestNumber(&a,&b);
//    std::cout << *largest_ptr << std::endl;//--dereference pointer: 200
//}

//int *MyFunction (){
//    int a{5};
//    int *ptr = new int;
//    *ptr = a;
//    return ptr;
//}
//
//int main(){
//    int *ptr{MyFunction()};
//    delete ptr;
//}


//--Unsafe

//int* Function1(){
//    int var{5};
//    return &var;
//}
//
//int* Function2(){
//    int var{5};
//    int *ptr{&var};
//    return ptr;
//}
//
//int main(){
//    int *ptr1{Function1()};
//    int *ptr2{Function2()};
//}

//--References
//int main(){
//    int i{2}, j{3};
//    double d{3.14};
//
////--declare reference variables
//    int    &r = i;
//    double &s = d;
//
//    std::cout << "Value of i : " << i << std::endl;//--2
//    std::cout << "Value of i reference : " << r  << std::endl;//2
//
//    std::cout << "Value of d : " << d << std::endl;//--3.14
//    std::cout << "Value of d reference : " << s  << std::endl;//--3.14
//
//}