#include <iostream>
#include "Kvector.h"
using namespace std;
Kvector::Kvector(int sz, int value) : len(sz) {
    cout << this << " : Kvector(" << sz << ", " << value << ")\n";
    if(!sz) { m = NULL; return; }
    m = new int[sz];
    for(int i = 0; i < sz; i++) {
        m[i] = value;
    }
}

Kvector::Kvector(const Kvector &v) {
    cout << this << " : Kvector(*" << &v << ")\n";
    len = v.len;
    if(!len) { m = NULL; return ;}
    m = new int[len];
    for(int i = 0; i < len; i++) {
        m[i] = v.m[i];
    }
}

Kvector::~Kvector() {
        cout << this << " : ~Kvector() \n";
        delete[] m;
}

// void Kvector::print() const {
//     for(int i = 0; i < len; i++) {
//         cout << m[i] << ' ';
//     }
//     cout << '\n';
// }

Kvector& Kvector::operator=(const Kvector &a) {
    cout << "Kvetor::operator= " << &a << '\n';
    if(this != &a) {
        delete[] m;
        len = a.len;
        m = new int[len];
        for(int i = 0; i < len; i++) {
            m[i] = a.m[i];
        }
    }
    return *this;
}
// void Kvector::clear() {
//     delete[] m;
//     m = nullptr;
//     len = 0;
// }

bool operator==(const Kvector &a, const Kvector &b) {
    if(a.len == b.len) {
        for(int i = 0; i < a.len; i++) {
            if(a.m[i] != b.m[i]) return false;
        }
        return true;
    }
    return false;
}
bool operator!=(const Kvector &a, const Kvector &b) {
    return !(a == b);
}
ostream& operator<<(ostream& os, const Kvector &a) {
    for(int i = 0; i < a.len; i++) {
        os << a.m[i] << ' ';
    }
    return os;
}