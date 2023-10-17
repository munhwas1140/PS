#include <iostream>
#include "Avector.h"   
Avector::Avector(int sz, int v, const char *t) : Kvector(sz, v) {
    cout << this << " : Avector(" << sz << ", " << v << ", \"" << t << "\")\n";
    for(int i = 0; i < N; i++) table[i] = t[i];
}
// Avector::Avector(const Avector &v) : Kvector(v) {
//     cout << this << " : Avector(*" << &v << ")\n";
//     setTable(v.table);
// }
// Avector::~Avector() {
//     cout << this << " : ~Avector() \n";
//     delete[] table;
// }
void Avector::setTable(const char *t) {
    for(int i = 0; i < N; i++) table[i] = t[i];
}
void Avector::print() const {
    cout << "Avector with table " << table << '\n';
    for(int i = 0 ; i < len; i++) {
        cout << m[i] << ' ';
    }
    cout << '\n';
}
// Avector& Avector::operator=(const Avecto  r& v) {
//     setTable(v.table);
//     this->Kvector::operator=(v);
//     return *this;
// }
ostream& operator<<(ostream& os, const Avector& v) {
    for(int i = 0; i < v.len; i++) {
        os << v.table[v.m[i] % N] << ' ';
    }
    return os;
}