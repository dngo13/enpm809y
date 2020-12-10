#include <iostream>

using namespace std;

int main() {
    cout << "Hello ENPM809Y" << std::endl;
    int num_students{15};
    cout << "The class has " << num_students << "students." << endl;
    cout << "Please enter your date of birth in the format of: d m y: " << endl;
    int d, m, y;
    cin >> d >> m >> y;
    cout << "Your date of birth is " << m << "/" << d << "/" << y;



    return 0;
}
