// Diane Ngo 
// Exercise 1 - Structure of a C++ Program
#include <iostream>

using namespace std;

int main() {
    cout << "Hello ENPM809Y" << std::endl;
    //Initialize int variable num_students
    int num_students{15};
        cout << "The class has " << num_students << " students." << endl;

    //******************************
    // Asks user input for their birthday and prints it out
    cout << "Please enter your date of birth in the format of: d m y: " << endl;
    int d, m, y;
    cin >> d >> m >> y;
    cout << "Your date of birth is " << m << "/" << d << "/" << y;

    return 0;
}
