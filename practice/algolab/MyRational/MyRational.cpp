#include "MyRational.h"
myRational::myRational(long num, long den) : _num(num), _den(den) { 
    this->reduce();
}
ostream &operator <<(ostream &outStream, const myRational& r) {
    if (r._num == 0)
        outStream << 0;
    else if (r._den == 1)
        outStream << r._num;
    else
        outStream << r._num << "/" << r._den;
return outStream;
}
myRational::myRational(const myRational& x) {
    _num = x._num;
    _den = x._den;
}
long myRational::getNumerator() const {
    return _num;
}
long myRational::getDenominator() const {
    return _den;
}
// myRational myRational::reciprocal() const {
//     long GCD = gcd(_num,_den);
    
// }

myRational myRational::operator+(const myRational &x) const {
    long g = gcd(_den, x._den);
    myRational tmp(_num * x._den + x._num * _den, _den * x._den);
    tmp.reduce();
    return tmp;
}
myRational myRational::operator+(const long &x) const {
    myRational tmp(_num + _den * x, _den);
    return tmp;
}
myRational myRational::operator-(const myRational &x) const {
    long g = gcd(_den, x._den);
    myRational tmp(_num * x._den - x._num * _den, _den * x._den);
    tmp.reduce();
    return tmp;
}
myRational myRational::operator-(const long &x) const {
    myRational tmp(_num - _den * x, _den);
    return tmp;
}
myRational myRational::operator*(const myRational &x) const {
    myRational tmp(_num * x._num, _den * x._den);
    tmp.reduce();
    return tmp;
}
myRational myRational::operator*(const long &x) const {
    myRational tmp(_num * x, _den);
    tmp.reduce();
    return tmp;
}
myRational myRational::operator/(const myRational &x) const {
    if(x._den == 0) return myRational();
    myRational tmp(_num * x._den, _den * x._num);
    tmp.reduce();
    return tmp;
}
myRational myRational::operator/(const long &x) const {
    if(x == 0) return myRational();
    myRational tmp(_num, _den * x);
    tmp.reduce();
    return tmp;
}

myRational& myRational::operator=(const myRational &x){
    _num = x._num;
    _den = x._den;
    return *this;
}
myRational& myRational::operator=(const long &x){
    _num = x;
    _den = 1;
    return *this;
}

myRational& myRational::operator+=(const myRational &x){
    *this = *this + x;
    return *this;
}
myRational& myRational::operator+=(const long &x){
    *this = *this + x;
    return *this;
}
myRational& myRational::operator-=(const myRational &x){
    *this = *this - x;
    return *this;
}
myRational& myRational::operator-=(const long &x){
    *this = *this - x;
    return *this;
}
myRational& myRational::operator*=(const myRational &x){
    *this = *this * x;
    return *this;
}
myRational& myRational::operator*=(const long &x){
    *this = *this * x;
    return *this;
}
myRational& myRational::operator/=(const myRational &x){
    *this = *this / x;
    return *this;
}
myRational& myRational::operator/=(const long &x){
    *this = *this / x;
    return *this;
}

myRational& myRational::operator++() {
    this->_num += this->_den;
    return *this;
}
myRational myRational::operator++(int) {
    myRational tmp(*this);
    this->_num += this->_den;
    return tmp;
}
myRational& myRational::operator--() {
    this->_num -= this->_den;
    return *this;
}
myRational myRational::operator--(int) {
    myRational tmp(*this);
    this->_num -= this->_den;
    return tmp;
}

myRational myRational::operator-() {
    return myRational(-_num, _den);
}

bool myRational::operator==(const myRational &x) {
    return _num == x._num && _den == x._den;
}
bool myRational::operator!=(const myRational &x) {
    return !(*this == x);
}
bool myRational::operator<(const myRational &x) const {
    long a = _num * x._den;
    long b = x._num * _den;
    if(_den * x._den < 0) {
        a *= -1;
        b *= -1;
    }
    return a < b;
}
bool myRational::operator<(const long &x) const {
    myRational tmp(x,1);
    long a = _num * tmp._den;
    long b = tmp._num * _den;
    if(_den * tmp._den < 0) {
        a *= -1;
        b *= -1;
    }
    return a < b;
}
bool myRational::operator>(const myRational &x) const {
    long a = _num * x._den;
    long b = x._num * _den;
    if(_den * x._den < 0) {
        a *= -1;
        b *= -1;
    }
    return a > b;
}
bool myRational::operator>(const long &x) const {
    myRational tmp(x,1);
    long a = _num * tmp._den;
    long b = tmp._num * _den;
    if(_den * tmp._den < 0) {
        a *= -1;
        b *= -1;
    }
    return a > b;
}
bool myRational::operator<=(const myRational &x) const {
    long a = _num * x._den;
    long b = x._num * _den;
    if(_den * x._den < 0) {
        a *= -1;
        b *= -1;
    }
    return a <= b;
}
bool myRational::operator<=(const long &x) const {
    myRational tmp(x,1);
    long a = _num * tmp._den;
    long b = tmp._num * _den;
    if(_den * tmp._den < 0) {
        a *= -1;
        b *= -1;
    }
    return a <= b;
}
bool myRational::operator>=(const myRational &x) const {
    long a = _num * x._den;
    long b = x._num * _den;
    if(_den * x._den < 0) {
        a *= -1;
        b *= -1;
    }
    return a >= b;
}
bool myRational::operator>=(const long &x) const {
    myRational tmp(x,1);
    long a = _num * tmp._den;
    long b = tmp._num * _den;
    if(_den * tmp._den < 0) {
        a *= -1;
        b *= -1;
    }
    return a >= b;
}

istream &operator >>(istream &inStream, myRational& r) {
    inStream >> r._num >> r._den;
    if (r._den == 0) {
        r._num = 0; 
        r._den = 1;
    }
    r.reduce();
    return inStream;
}

long myRational::gcd(long m, long n) const {
    if (m == n)
        return n;
    else if (m < n)
        return gcd(m, n-m);
    else
        return gcd(m-n, n);
}
void myRational::reduce() {
    if (_num == 0 || _den == 0) {
        _num = 0;
        _den = 1;
        return;
    }
    if (_den < 0) {
        _den *= -1;
        _num *= -1;
    }
    if (_num == 1)
        return;
    int sgn = (_num < 0 ? -1 : 1);
    long g = gcd(sgn * _num, _den);
    _num /= g;
    _den /= g;
} 