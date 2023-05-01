#include <bits/stdc++.h>
using namespace std;

class A {
    const int c;
    int &r;
    // r에 대한 메모리는 생기지 않는다.

public:
    A(int &x, int c = 0) : c(c), r(x) {
        cout << this << " : A(int&, int) called\n";
    }

    ~A() { cout << this << " : ~A() called\n";}

    int getR() { return r;}
    int getC() { return c;}
    void setR(int v) { r = v;}
};
int g;
A a2(g, 3);
int main() {

    // A a[10];
    // A a[3] = {A(x, y), A(x, y), A(x, y)};
    //
    // A *a = new A();
    // A *a = new A[10];
    // 클래스의 동적 할당. default constructor 가 필요함
    int i = 100;
    A a1(i, 10);
    cout << a1.getR() << '\n'; a1.setR(-1);
    cout << a1.getR() << " i : " << i << '\n';
    cout << a1.getC() << '\n';
    cout << '\n';
    cout << a2.getR() << '\n'; a2.setR(-2);
    cout << a2.getR() << " g : " << g << '\n';
    cout << a2.getC() << '\n';
    return 0;
}
