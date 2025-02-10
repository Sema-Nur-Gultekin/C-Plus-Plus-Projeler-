#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;

    virtual ~Shape() {};
};

class Circle : public Shape {
private:
    double yaricap;

public:
    Circle(double r) : yaricap(r) {}

    double area() const {
        return 3.14 * yaricap * yaricap;
    }
};

class Square : public Shape {
private:
    double kenar;

public:
    Square(double k) : kenar(k) {}

    double area() const {
        return kenar * kenar;
    }
};

int main() {
  
    Shape* circle = new Circle(5.0);
    Shape* square = new Square(4.0);

    cout << "Circle area: " << circle->area() << endl;
    cout << "Square area: " << square->area() << endl;

    delete circle;
    delete square;

    return 0;
}

