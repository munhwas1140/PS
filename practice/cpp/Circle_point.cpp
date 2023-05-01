#include <bits/stdc++.h>
using namespace std;
class Point {
    int x, y;

public:
    // Point() {}
    Point(int x, int y) : x(x) {
        this->y = y;
    }
    
    void print() {
        cout << x << ' ' << y << '\n';
    }
};
class Circle {
    Point center;
    int radius;

public:
    Circle(int x, int y, int z) : center(x,y), radius(z){
        // center = Point(x,y);
    }
    void print() {
        this->center.print();
        cout << this->radius << '\n';
    }
};

int main() {
    Circle c1(4,5,6);
    c1.print();
    return 0;
}