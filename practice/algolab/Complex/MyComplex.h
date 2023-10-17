#ifndef _MYCOMPLEX_H_
#define _MYCOMPLEX_H_
#include <iostream>
using namespace std;
class myComplex {
public:
    int realPart;
    int imaginaryPart;
    int norm() const;
    
    myComplex(int real = 0, int imag = 0);
    myComplex(const myComplex& number);
    int getRealPart() const;
    int getImaginaryPart() const;
    void setRealPart(int real);
    void setImaginaryPart(int imag);
    void set(int real, int imag);
    bool operator >(const myComplex& number) const;
    bool operator <(const myComplex& number) const;
    bool operator >=(const myComplex& number) const;
    bool operator <=(const myComplex& number) const;
    myComplex& operator++();
    myComplex operator++(int);
    myComplex& operator--();
    myComplex operator--(int);
    myComplex operator *(const myComplex& number) const;
    myComplex operator *(const int value) const;
    myComplex operator +(const myComplex& number) const;
    myComplex operator +(const int value) const;
    myComplex operator -(const myComplex& number) const;
    myComplex operator -(const int value) const;
    myComplex& operator +=(myComplex& number);
    myComplex& operator +=(const int value);
    myComplex& operator -=(myComplex& number);
    myComplex& operator -=(const int value);
    myComplex& operator *=(myComplex& number);
    myComplex& operator *=(const int value);
    myComplex& operator =(const myComplex& number);
    myComplex& operator =(const int value);
    friend myComplex operator ~(const myComplex &number);
    bool operator ==(const myComplex& number) const;
    bool operator !=(const myComplex& number) const;
    myComplex operator -();
    friend ostream& operator<<(ostream &os, const myComplex &a);
    friend istream& operator>>(istream &is, myComplex &a);
};
#endif