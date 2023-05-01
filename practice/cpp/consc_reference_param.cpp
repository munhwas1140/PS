#include <bits/stdc++.h>
using namespace std;
int cfoo(const int &c) { return c + 1; }
int foo(int &c) { return c + 1; }

int cfoo2(const int *c) { return *c + 1; }
int foo2(int *c) {return *c + 1; }

int main() {
    int i = 10;
    const int c = 20;


    cout << cfoo(i) << '\n'; // const LHS <- non-const RHS, OK
    cout << cfoo(2) << '\n'; // const LHS <- const RHS, OK
    cout << foo(i) << '\n';  // non-const LHS <- non_const RHS, OK
    cout << foo(2) << '\n';  // non-const LHS <- const RHS, ERROR

    cout << cfoo2(&i) << '\n'; //cosnt LHS <- non-const RHS, OK
    cout << cfoo2(&c) << '\n'; //const LHS <- const RHS, OK
    cout << foo2(&i) << '\n'; //non-const LHS <- non-const RHS,OK
    cout << foo2(&c) << '\n'; //non-const LHS <- const RHS, ERROR
    return 0;
}