#include <iostream>
#include "Kvector.h"
using namespace std;
#define N 3

class Avector : public Kvector {
    char table[N];
public:
    Avector(int sz = 0, int v = 0, const char *t = "abc");
    // Avector(const Avector &v);
    // ~Avector();
    void print() const;
    void setTable(const char *t);
    // Avector& operator=(const Avector& v);
    friend ostream& operator<<(ostream& os, const Avector& v);
};