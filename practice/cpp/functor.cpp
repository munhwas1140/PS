#include <bits/stdc++.h>
using namespace std;
template <class T>
struct my_greater{
    bool operator()(T a, T b) {
        return a > b;
    }
};

template <class F>
bool my_f(int a, int b, F func) { //functor, function pointer 를 인자로 받는다.
    return func(a, b);
}

int main() {
    int i = 2, j = 1;
    bool r;
    // my_grater<int> m;
    greater<int> m;
    r = m(i, j);
    cout << r << '\n';
    r = my_f(i, j, m);
    cout << r << endl;
    r = my_f(i, j, greater<int>());
    cout << r << '\n';
}