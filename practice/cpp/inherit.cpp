#include <bits/stdc++.h>
using namespace std;
class A {
            int v;
protected:  int t;
public:     int p;
    void f() {
        v = 1;
        t = 2;
        p = 3;
    }
};

class SubA : public A {
public:
    void g() {
        // v = 10; compile error
        t = 20;
        p = 30;
    }
};

class Other {
public:
    void h() {
        A obj1;
        // obj1.v = 100;
        // obj1.t = 200;
        obj1.p = 300;
    
        SubA s;
        s.f();
        s.g();
    }
};

int main() {
    Other t;
    t.h();
    return 0;
}