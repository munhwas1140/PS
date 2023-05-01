#include <bits/stdc++.h>
using namespace std;
class NonPositiveException{
public:
    int v;
    NonPositiveException(int v = 0) : v(v) {}
};

class ZeroException : public NonPositiveException{};

void foo() {
    try{
        int v;
        cout << "enter a value : ";
        cin >> v;
        if(v < 0) throw NonPositiveException(v);
        if(v == 0) throw ZeroException();
    } catch(...) {
        cout << "FOO EXCEPTION" << '\n';
        throw;
    }
    // throw 할 경우 foo 출력 안됨.
    cout << "foo" << '\n';
}

int main() {
    int v;
    try {
        foo();
    } catch(ZeroException& e) {
        cout << "Zero" << '\n';
    } catch(NonPositiveException& e) {
        cout << "NonPositive Value : " << e.v << '\n';
    }
    cout << "main" <<'\n';
    return 0;
}
// 상속 -> class B : public A -> B is a A;
// has a 관계일떄는 상속 x 인스턴스로 추가함