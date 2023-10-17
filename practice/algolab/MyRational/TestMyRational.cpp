#include <bits/stdc++.h>
#include "MyRational.h"
using namespace std;

myRational operator+(const int &a, const myRational &x) {
    myRational tmp = x;
    return x + a;
}
myRational operator-(const int &a, const myRational &x) {
    myRational tmp(a,1);
    return tmp - x;
}
myRational operator*(const int &a, const myRational &x) {
    myRational tmp = x;
    return x * a;
}
myRational operator/(const int &a, const myRational &x) {
    myRational tmp(a,1);
    return tmp / x;
}

void testSimpleCase();
void testDataFromFile();
int main() {
    testSimpleCase();
    testDataFromFile();
}
void testSimpleCase() {
    myRational frac1(2), frac2(3, 2), frac3(6, 4), frac4(12, 8), frac5, frac6, frac7;
    cout << frac1 << " " << frac2 << " " << frac3 << " "
    << frac4 << " " << frac5 << endl;
    cout << frac1.getNumerator() << " " << frac1.getDenominator() << endl;
    cout << frac1 * frac2 << " "
    << frac1 + frac3 << " "
    << frac2 - frac1 << " "
    << frac3 / frac2 << endl;

    cout << ((frac1 < frac2) ? 1 : 0) << " "
    << ((frac1 <= frac2) ? 1 : 0) << " "
    << ((frac1 > frac2) ? 1 : 0) << " "
    << ((frac1 >= frac2) ? 1 : 0) << " "
    << ((frac1 == frac2) ? 1 : 0) << " "
    << ((frac1 != frac2) ? 1 : 0) << " "
    << ((frac2 < frac3) ? 1 : 0) << " "
    << ((frac2 <= frac3) ? 1 : 0) << " "
    << ((frac2 > frac3) ? 1 : 0) << " "
    << ((frac2 >= frac3) ? 1 : 0) << " "
    << ((frac2 == frac3) ? 1 : 0) << " "
    << ((frac2 != frac3) ? 1 : 0) << endl;
    cout << (frac6 = frac3) << " ";
    cout << (frac6 += frac3) << " ";
    cout << (frac6 -= frac3) << " ";
    cout << (frac6 *= frac3) << " ";
    cout << (frac6 /= frac3) << endl;
    cout << -frac6 << endl;
    frac6 = (++frac4) + 2;
    frac7 = 2 + (frac4++);
    cout << frac4 << " " << frac6 << " " << frac7 << endl;
    frac6 = (--frac4) - 2;
    frac7 = 2 - (frac4--);
    cout << frac4 << " " << frac6 << " " << frac7 << endl;
    cout << 2 * frac3 << " " << frac3 * 2 << " "
    << 2 / frac3 << " " << frac3 / 2 << endl;
}
void testDataFromFile() {
    ifstream is;
    is.open("input.txt");

    int tc;
    is >> tc;
    cout << tc << '\n';
    while(tc--) {
        int n; is >> n;
        vector<myRational> a;
        for(int i = 0; i < n; i++) {
            myRational tmp;
            is >> tmp._num >> tmp._den;
            a.push_back(tmp);
        }
        sort(a.begin(), a.end());
        for(int i = 0; i < n; i++) {
            a[i].reduce();
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
    return ;
} 