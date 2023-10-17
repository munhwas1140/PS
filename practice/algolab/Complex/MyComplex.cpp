#include <iostream>
#include "MyComplex.h"
myComplex::myComplex(int real, int imag) {
    realPart = real;
    imaginaryPart = imag;
}
myComplex::myComplex(const myComplex& number) {
    realPart = number.realPart;
    imaginaryPart = number.imaginaryPart;
}
int myComplex::getRealPart() const {
    return realPart;
}
int myComplex::getImaginaryPart() const {
    return imaginaryPart;
}
void myComplex::setRealPart(int real) {
    realPart = real;
}
void myComplex::setImaginaryPart(int imag) {
    imaginaryPart = imag;
}
void myComplex::set(int real, int imag) {
    realPart = real;
    imaginaryPart = imag;
}
myComplex& myComplex::operator++() {
    this->realPart++;
    return *this;
}
myComplex myComplex::operator++(int) {
    myComplex tmp(*this);
    this->realPart++;
    return tmp;
}
myComplex& myComplex::operator--() {
    this->realPart--;
    return *this;
}
myComplex myComplex::operator--(int) {
    myComplex tmp(*this);
    this->realPart--;
    return tmp;
}
myComplex myComplex::operator *(const myComplex& number) const {
    int newReal = realPart * number.realPart - imaginaryPart * number.imaginaryPart;
    int newImag = realPart * number.imaginaryPart + imaginaryPart * number.realPart;
    return myComplex(newReal, newImag);
}
myComplex myComplex::operator *(const int value) const {
    int newReal = realPart * value;
    int newImag = imaginaryPart * value;
    return myComplex(newReal, newImag);
}
myComplex myComplex::operator +(const myComplex& number) const {
    int newReal = realPart + number.realPart;
    int newImag = imaginaryPart + number.imaginaryPart;
    return myComplex(newReal, newImag);
}
myComplex myComplex::operator +(const int value) const {
    return myComplex(value) + (*this);
}
myComplex myComplex::operator -(const myComplex& number) const {
    int newReal = realPart - number.realPart;
    int newImag = imaginaryPart - number.imaginaryPart;
    return myComplex(newReal, newImag);
}
myComplex myComplex::operator -(const int value) const {
    myComplex tmp(*this);
    tmp.realPart -= value;
    return tmp;
}
myComplex& myComplex::operator +=(myComplex& number) {
    (*this) = (*this) + number;
    return *this;
}
myComplex& myComplex::operator +=(const int value) {
    (*this) = (*this) + value;
    return *this;
}
myComplex& myComplex::operator -=(myComplex& number) {
    (*this) = (*this) - number;
    return *this;
}
myComplex& myComplex::operator -=(const int value) {
    (*this) = (*this) - value;
    return *this;
}
myComplex& myComplex::operator *=(myComplex& number) {
    (*this) = (*this) * number;
    return *this;
}
myComplex& myComplex::operator *=(const int value) {
    (*this) = (*this) * value;
    return *this;
}
myComplex& myComplex::operator =(const myComplex& number) {
    this->realPart = number.realPart;
    this->imaginaryPart = number.imaginaryPart;
    return *this;
}
myComplex& myComplex::operator =(const int value) {
    realPart = value;
    imaginaryPart = 0;
    return *this;
}
bool myComplex::operator ==(const myComplex& number) const {
    return (realPart == number.realPart) &&
    (imaginaryPart == number.imaginaryPart);
}
bool myComplex::operator !=(const myComplex& number) const {
    return !((*this) == number);
}

bool myComplex::operator >(const myComplex& number) const {
    return norm() > number.norm();
}
bool myComplex::operator <(const myComplex& number) const {
    return norm() < number.norm();
}
bool myComplex::operator >=(const myComplex& number) const {
    return norm() >= number.norm();
}
bool myComplex::operator <=(const myComplex& number) const {
    return norm() <= number.norm();
}
myComplex myComplex::operator -() {
    return myComplex(-realPart, -imaginaryPart);
}

int myComplex::norm() const
{
    return realPart * realPart + imaginaryPart * imaginaryPart;
}
ostream& operator<<(ostream &os, const myComplex &a) {
    os << "(" << a.realPart << "," << a.imaginaryPart << ")";
    return os;
}
istream& operator>>(istream &is, myComplex &a) {
    is >> a.realPart >> a.imaginaryPart;
    return is;
}
myComplex operator ~(const myComplex &number) {
    myComplex tmp(number.realPart, -number.imaginaryPart);
    return tmp;
}