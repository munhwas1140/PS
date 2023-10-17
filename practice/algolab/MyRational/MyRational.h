#ifndef _MYRATIONAL_H_
#define _MYRATIONAL_H_
#include <iostream>
using namespace std;
class myRational {
public:
 // 분수는 항상 내부적으로 기약분수로 표현하며, 또한 항상 _den>0 이다. long _num; // numerator
    myRational(long num = 0,long den = 1);
    myRational(const myRational &x);
    long getNumerator() const;
    long getDenominator() const; 
    // myRational reciprocal() const;

    myRational operator+(const myRational &x) const;
    myRational operator+(const long &x) const;
    myRational operator-(const myRational &x) const;
    myRational operator-(const long &x) const;
    myRational operator*(const myRational &x) const;
    myRational operator*(const long &x) const;
    myRational operator/(const myRational &x) const;
    myRational operator/(const long &x) const;


    bool operator==(const myRational &x);
    bool operator!=(const myRational &x);
    myRational& operator=(const myRational &x);
    myRational& operator=(const long &x);
    myRational& operator+=(const myRational &x);
    myRational& operator+=(const long &x);
    myRational& operator-=(const myRational &x);
    myRational& operator-=(const long &x);
    myRational& operator*=(const myRational &x);
    myRational& operator*=(const long &x);
    myRational& operator/=(const myRational &x);
    myRational& operator/=(const long &x);

    myRational& operator++();
    myRational operator++(int);
    myRational& operator--();
    myRational operator--(int);
    myRational operator-();

    bool operator<(const myRational &x) const;
    bool operator<(const long &x) const;
    bool operator>(const myRational &x) const;
    bool operator>(const long &x) const;
    bool operator<=(const myRational &x) const;
    bool operator<=(const long &x) const;
    bool operator>=(const myRational &x) const;
    bool operator>=(const long &x) const;
    friend istream& operator>>(istream &inStream, myRational &r);
    friend ostream &operator <<(ostream &outStream, const myRational& r);
    long _den,_num; // denominator
    long gcd(long m, long n) const; // 최대공약수
    void reduce();
};
#endif 