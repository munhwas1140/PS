#include <iostream>
#include <exception>
#include "BitSet.h"
using namespace std;

IncompatibleException::IncompatibleException(int a, int b) : v1(a), v2(b) {
    // cout << "In + operation, the operands are not compatible." << '\n';
}
BitSet::BitSet(int sz) : Bvector(sz) {}
void BitSet::insert(int v) {
    set(v);
}
BitSet operator+(const BitSet &a, const BitSet &b) {
    try {
        if(a.NBITS != b.NBITS) throw IncompatibleException(a.NBITS,b.NBITS);
    } catch(IncompatibleException& e) {
        // cout << "The size of the first BitSet is " << e.v1 << '\n';
        // cout << "The size of the second BitSet is " << e.v2 << '\n';
        throw;
    }
    BitSet tmp(a.NBITS);
        for(int i = 0; i < a.len; i++) {
            tmp.u_m[i] = a.u_m[i] | b.u_m[i];
        }
    return tmp;
}
ostream& operator<<(ostream& os, const BitSet &s) {
    os << "{ "; 
    for(int i = 0; i < s.NBITS; i++) {
        if(s.bit(i)) os << i << ' ';
    }
    os << "}";
    return os;
}