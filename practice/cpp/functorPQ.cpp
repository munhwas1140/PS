#include <bits/stdc++.h>
using namespace std;
class Rectangle{
    int width, height;
public:
    Rectangle(int w = 0, int h = 0) : width(w), height(h) {}
    int area() const{return width * height; }
    friend ostream& operator<<(ostream &os, const Rectangle &r);
};
ostream& operator<<(ostream &os, const Rectangle &r) {
    os << r.width << " X " << r.height << '\n';
    return os;
}

class RecCmp {
public:
    bool operator()(const Rectangle &r1, const Rectangle &r2) {
        return r1.area() < r2.area();
    }
};

int main() {
    priority_queue<Rectangle, vector<Rectangle>, RecCmp> pq;
    pq.push(Rectangle(4, 5));
    pq.push(Rectangle(3, 5));
    pq.push(Rectangle(4, 8));

    while(!pq.empty()) {
        cout << pq.top();
        pq.pop();
    }
    return 0;
}