#include <bits/stdc++.h>
using namespace std;

class Shape {
protected:
    int x, y;
public:
    void setOrigin(int x, int y) {
        this->x = x;
        this->y = y;
    }
    virtual void draw() {
        cout << "Shape ( " << x << ", " << y << " )";
    }
};

class Rectangle : public Shape {
    int width, height;
public:
    void setWidth(int w) {width = w;}
    void setHeight(int h) {height = h;}
    void draw() {
        Shape::draw();
        cout << "Rectangle : " << width << " x " << height;
    }
};

class Circle : public Shape {
    int radius;
public:
    void setRadius(int r) {radius = r;}
    void draw() {
        Shape::draw();
        cout << "Circle : " << radius;
    }
};

void move(Shape &s, int dx, int dy) {
    s.setOrigin(dx, dy);
}
int main() {
    // Rectangle r;
    // r.setOrigin(1, 1);
    // r.setWidth(3);
    // r.draw(); cout << '\n';

    // Shape *p_s = &r;
    // p_s->setOrigin(10,10);
    // // p_s->setWidth(100); 
    // p_s->draw() ; cout << '\n';

    // Rectangle *p_r = &r;
    // p_r = (Rectangle *)p_s;
    // p_r->setOrigin(8, 8);
    // p_r->setWidth(16);
    // p_r->draw(); cout << '\n';

    // ((Circle *)p_s)->setRadius(11);
    // ((Circle *)p_s)->draw(); cout << '\n';
    // p_r->draw(); cout << '\n';
    // Shape &s = r;
    // s.setOrigin(5, 5);
    // // s.setWidth(7);
    // s.draw(); cout << '\n';

    // //Rectangle &r_r = (Rectangle)s; 


    Rectangle r;
    r.setOrigin(1,1);
    r.setWidth(3);
    r.draw(); cout << '\n';

    Circle c;
    c.setOrigin(4, 4);
    c.setRadius(5);
    c.draw(); cout << '\n';

    Shape *p_s;
    p_s = &r;
    p_s->draw(); cout << '\n';
    p_s = &c;
    p_s->draw(); cout << '\n';

    Shape &s1 = r;
    s1.draw(); cout << '\n';
    Shape &s2 = c;
    s2.draw(); cout << '\n';

    return 0;
}