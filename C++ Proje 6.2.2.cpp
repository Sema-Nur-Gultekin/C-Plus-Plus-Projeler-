#include <iostream>
using namespace std;

class Vector3d;

class Point3d {
private:
    double x, y, z;

public:
    Point3d(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}

    void moveByVector(const Vector3d& v);
    void print() const {
        cout << "Point(" << x << ", " << y << ", " << z << ")\n";
    }
};

class Vector3d {
private:
    double x, y, z;

public:
    Vector3d(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}

    friend void Point3d::moveByVector(const Vector3d& v);
};

void Point3d::moveByVector(const Vector3d& v) {
    x += v.x;
    y += v.y;
    z += v.z;
}

int main() {

    Point3d p(1, 2, 3);
    Vector3d v(1, -1, 0);

    p.moveByVector(v);
    p.print(); 

    return 0;
}

