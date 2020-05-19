#include <iostream>
#include <string>

using namespace std;

class Car {
protected:
    string company;
    string model;
public:
    Car(string comp, string mod) : company(comp), model(mod) {
        cout << company << " " << model << endl;
    }
};

class PassengerCar : virtual public Car {
public:
    PassengerCar(string comp, string mod) : Car(comp, mod) {
        cout << comp << " " << mod << endl;
    }
};

class Bus : virtual public Car {
public:
    Bus(string comp, string mod) : Car(comp, mod) {
        cout << comp << " " << mod << endl;
    }
};

class Minivan : public PassengerCar, public Bus {
public:
    Minivan(string comp, string mod) : Car(comp, mod), PassengerCar(comp, mod), Bus(comp, mod) {
        cout << comp << " " << mod << endl;
    }
};

int main() {
    setlocale(0, "");
    Car car("Nissan", "Qashqai");
    PassengerCar passenger("Volvo", "XC90");
    Bus bus("ПАЗ", "Вектор");
    Minivan mini("Peugeot", "Traveller ");
return 0;
}

