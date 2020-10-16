#include <iostream>
#include <cassert>

#include "Villain/villain.h"

class Villain{
public:
    std::string name_{"Villain"};
    double health_{100};
    int life_{1};

    void TakeDamage(double damage){
        health_ -= damage;
        Print();//--Print() can be called even thought it is defined after
    }

    void Print(){
        std::cout << "n="<< name_ << ", h=" << health_ << ", l=" << life_ << std::endl;
    }

};

int main() {
    Villain astaroth {"Astaroth", 100, 2};
    astaroth.life_ = 3;
    astaroth.Print();
    std::cout << sizeof(astaroth);

    Villain *firebrand{"Firebrand", 100, 1};
    firebrand->Print();
    delete firebrand;

}

/**
***************
 * Exercise #1
***************
*/
//--Create a class MyInts that hold 2 integers
//--This class should have 2 attributes to hold the integers
//--Create 2 methods:
//   Set() to assign values to the integers,
//   Print to print the values of the variables.
//--The following main should compile
//int main()
//{
//    MyInts i1;
//    i1.Set(1,1); // set i1 values to (1,1)
//    MyInts i2{2, 2}; // initialize i2 values to (2, 2)
//
//    i1.Print();//--prints Pair(1, 1)
//    i2.Print();//--prints Pair(2, 2)
//}



/**
***************
 * Destructor
***************
 */
//class IntArray
//{
//private:
//    int *m_array{};
//    int m_length{};
//
//public:
//    IntArray(int length) //--constructor
//    {
//        assert(length > 0);
//
//        m_array = new int[length]{};
//        m_length = length;
//    }
//
//    ~IntArray() // destructor
//    {
//        // Dynamically delete the array we allocated earlier
//        delete[] m_array;
//    }
//
//    void setValue(int index, int value) { m_array[index] = value; }
//    int getValue(int index) { return m_array[index]; }
//
//    int getLength() { return m_length; }
//};
//
//int main()
//{
//    IntArray ar(10); // allocate 10 integers
//    for (int count{0}; count < ar.getLength(); ++count)
//        ar.setValue(count, count+1);
//
//    std::cout << "The value of element 5 is: " << ar.getValue(5) << '\n';
//}