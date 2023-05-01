#include <iostream>
#include "Bvector.h"
using namespace std;

class IncompatibleException : public std::exception{
public:
    int v1, v2;
    IncompatibleException(int a, int b);
};

class BitSet : public Bvector {
public:
    BitSet(int sz = 32);
    void insert(int v);
    friend BitSet operator+(const BitSet &a, const BitSet &b);
    friend ostream& operator<<(ostream& os, const BitSet &s);
};