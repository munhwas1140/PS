#include <bits/stdc++.h>
using namespace std;

enum COMPLEX_PART {RE, IM};

class Complex {
    double re, im;
public:
    Complex(double r = 0, double i = 0);
    operator double() const { return re; }
    // 리턴타입 명시 안하고 함수명이 리턴 타입이 됨.
    ~Complex() {}
    double real() {return re;}
    double imag() {return im;}
    Complex& operator+=(const Complex &c);
    Complex add(const Complex &c) const;
    Complex& operator++() {re += 1; return *this;}
    Complex operator++(int) {
        Complex tmp(*this);
        operator++();
        return tmp;
    }
    double& operator[](COMPLEX_PART idx) { return (idx ? im : re);}
    const double& operator[](COMPLEX_PART idx) const { return (idx ? im : re);}
    // Complex operator+(const Complex &c) const;
    friend Complex operator+(Complex c, const Complex &d);
    friend bool operator==(const Complex &c, const Complex &d);
    friend ostream& operator<<(ostream &os, const Complex &c);
    Complex& operator=(const Complex &c);
    void print() const;
};
Complex::Complex(double r, double i) : re(r), im(i) {}


// 멤버함수가 아니기때문에 Complex:: 는 필요 없음. friend 함수.
Complex operator+(Complex c, const Complex &d) {
    c += d;
    return c;
}
bool operator==(const Complex &c, const Complex &d) {
    return (c.re == d.re) && (c.im == d.re);
}
bool operator!=(const Complex &c, const Complex &d) {
    return !(c == d);
}

Complex& Complex::operator=(const Complex &c) {
    if(&c != this) {
        re = c.re;
        im = c.im;
    }
    return *this;
}
Complex& Complex::operator+=(const Complex &c) {
    re += c.re;
    im += c.im;
    return *this;
}
ostream& operator<<(ostream &os, const Complex &c) {
    os << c.re << " + " << c.im << "i ";
    return os;
}
// Complex Complex::operator+(const Complex &c) const {
//     Complex result(re + c.re, im + c.im);
//     return result;
// }
Complex Complex::add(const Complex &c) const{
    Complex result(re + c.re, im + c.im);
    return result;
}

void Complex::print() const {
    cout << re << " + " << im << "i" << '\n';
}

int main() {
    const Complex x(2,3);
    Complex y(-1,-3), z;
    double d = 2.71828;
    cout << "x = " << x << '\n';
    cout << "y = " << y << '\n';
    
    z = 3.14; // implicit double -> Complex
    // => z = Complex(3.14);
    
    cout << "z = " << z << '\n';
    
    d = y; // implicit Complex -> double
    // => d = double(y)
    
    cout << "d = " << d << '\n';
    z = Complex(d); // explicit double -> Complex
    cout << "z = " << z << '\n';
    d = double(x); // explicit Complex -> double;
    cout << "d = " << d << '\n';

    return 0;
}