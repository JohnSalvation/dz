#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Figure {
public:
    Figure(){}
    ~Figure(){}
    virtual double area() = 0;
};

class Parallelogram : public Figure {
protected:
    double height;
    double side;
public:
    Parallelogram(double h, double s) : height(h), side(s) {}
    double area() override {
    double S = side * height;
    return S;
    }
};

class Circle : public Figure {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() override {
    double S = 3.1415926535 * pow(radius, 2);
    return S;
    }
};

class Rectangle : public Parallelogram {
    double side_a;
    double side_b;
public:
    Rectangle(double h, double s) : Parallelogram(height, side) {
            side_a = h, side_b = s;
    }
    double area() override {
    double S = side_a * side_b;
    return S;
    }
};

class Square : public Parallelogram {
    double side;
public:
    Square(double s) : Parallelogram(height, side) {side = s;}
    double area() override {
    double S = pow(side, 2);
    return S;
    }
};

class Rhombus : public Parallelogram {
    double height;
    double side;
public:
    Rhombus(double h, double s) : Parallelogram(height, side) {
        height = h, side = s;
    }
    double area() override {
    double S = height * side;
    return S;
    }
};

int main() {
    setlocale(0, "");
    Parallelogram par(5,3);
    Circle cir(5);
    Rectangle rec(3,5);
    Square sq(3);
    Rhombus r(4,5);
    Figure *fig = &par;
    Figure *fig2 = &cir;
    Parallelogram *pal = &rec;
    Parallelogram *pal2 = &sq;
    Parallelogram *pal3 = &r;

    cout << "Площадь параллелограмма: " << fig->area() << endl;
    cout << "Площадь круга: " << fig2->area() << endl;
    cout << "Площадь прямоугольника: " << pal->area() << endl;
    cout << "Площадь квадрата: " << pal2->area() << endl;
    cout << "Площадь ромба: " << pal3->area() << endl;
return 0;
}
