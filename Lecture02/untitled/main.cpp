#include <iostream>
class Veh {
public:
    virtual void Drive(double speed) {
        std::cout << "Veh driving " << speed << std::endl;
    }
};

class Car: public Veh{
public:
    virtual void Drive(int speed) override{
        std::cout << "Driving int" << speed << std::endl;
    }

};b
int main() {
  Car car;
  car.Drive(4);
}
