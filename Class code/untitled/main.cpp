//Diane Ngo
//ENPM809Y
//Lecture 3 - User-defined Types and Data Structures
//Exercises

#include <iostream>
#include <array>
#include <vector>
using namespace std;

int main() {
    //Exercise 1**************************************************************************************************
    cout << "Exercise 1 from Lecture 3" << endl;
    //C Style Array
    cout << "C-style Array" << endl;
    int array_c[3]{9, 9, 9};
    for (int i = 0; i < 3; i++) { // for loop to print array
        cout << array_c[i] << " ";
    }
    cout << endl;
    int size_array_c;
    size_array_c = sizeof(array_c) / sizeof(*array_c);
    cout << "The size of the array is " << size_array_c << endl;
    array_c[0] = 1; //Modify 1st element
    array_c[2] = 7; //Modify last element
    cout << "C-style array with modified 1st and last element" << endl;
    for (int i = 0; i < 3; i++) { // for loop to print array
        cout << array_c[i] << endl;
    }
    cout << endl;

    //C++ Style Array
    cout << "C++ style array" << endl;
    array<int, 3> array_cp = {9, 9, 9};
    array_cp.fill(9);
    int size_array_cp;
    size_array_cp = array_cp.size();
    cout << "The size of the array is " << size_array_cp << endl;
    for (int i = 0; i < 3; i++) { // for loop to print array
        cout << array_cp[i] << " ";
    }
    cout << endl;
    array_cp[0] = 1; //Modify 1st element
    array_cp[2] = 7; //Modify last element
    cout << "C++ style array with modified 1st and last element" << endl;
    for (int i = 0; i < 3; i++) { // for loop to print array
        cout << array_cp[i] << endl;
    }
    cout << "=================================" << endl;
    //Exercise 2***************************************************************************************************
    cout << "Exercise 2 from Lecture 3" << endl;
    vector<int> vector_1{1000, 100, 10, 1};
    cout << "The size of the vector is " << vector_1.size() << endl;
    for (int i = 0; i < vector_1.size(); i++) {
        cout << vector_1[i] << ' ';
    }
    cout << endl;
    cout << "Please enter 4 integer numbers: ";
    int int1 = 0, int2 = 0, int3 = 0, int4 = 0;
    cout << "First: ";
    cin >> int1;
    cout << "Second: ";
    cin >> int2;
    cout << "Third: ";
    cin >> int3;
    cout << "Fourth: ";
    cin >> int4;
    vector_1[0] = int1;
    vector_1[1] = int2;
    vector_1[2] = int3;
    vector_1[3] = int4;
    cout << "The vector with at syntax: ";
    for (int i = 0; i < vector_1.size(); i++) {
        cout << vector_1.at(i) << ' ';
    }
    cout << endl;
    vector_1.push_back(2000);
    vector_1.erase(vector_1.begin() + 1, vector_1.begin() + 3);
    cout << "The vector modified: " << endl;
    for (int i = 0; i < 3; i++) { // for loop to print vector using array syntax
        cout << vector_1[i] << ' ';
    }
    cout << endl;
    cout << "The size of the vector is now " << vector_1.size() << endl;
}