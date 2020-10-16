// Diane Ngo
// Exercise 2
#include<iostream>

int main() {
    //C++-style array
    std::array<int, 3> array_cp = { 9, 9, 9 };
    std::cout << array_cp << std::endl;
    int size_array = size(array_cp);
    array_cp[0] = 1;
    std::cout << array_cp << std::endl;
    //C-style array

}