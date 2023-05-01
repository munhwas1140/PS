#include <iostream>
#ifndef __KVECTOR__
#define __KVECTOR__
using namespace std;

template<class T>
class Kvector;
template<class T>
bool operator==(const Kvector<T> &v, const Kvector<T> &w);
template<class T>
bool operator!=(const Kvector<T> &v, const Kvector<T> &w);
template<class T>
ostream& operator<<(ostream &os, const Kvector<T> &v);

template<class T>
class Kvector{
protected:
    T *m;
    int len;
public:
    Kvector<T>(int sz = 0, T value = 0);
    Kvector<T>(const Kvector<T> &v);
    virtual ~Kvector<T>();
    virtual void print() const {cout << "Kvector\n";}
    void clear() {delete[] m; m = NULL; len = 0;}
    int size() const { return len;}
    T sum() const {
        if(!len) return T();
        T s = m[0];
        for(int i = 1; i < len; i++) s += m[i];
        return s;
    }
    Kvector<T>& operator=(const Kvector<T> &a);
    friend bool operator==<>(const Kvector<T> &a, const Kvector<T> &b);
    friend bool operator!=<>(const Kvector<T> &a, const Kvector<T> &b);
    T& operator[](int idx) {return m[idx];}
    const T& operator[](int idx) const {return m[idx];}
    friend ostream& operator<<<>(ostream& os, const Kvector<T> &a);
};
template<class T>
Kvector<T>::Kvector(int sz, T value) : len(sz) {
    cout << this << " : Kvector(" << sz << ", " << value << ")\n";
    if(!sz) { m = NULL; return; }
    m = new T[sz];
    for(int i = 0; i < sz; i++) {
        m[i] = value;
    }
}

template<class T>
Kvector<T>::Kvector(const Kvector<T> &v) {
    cout << this << " : Kvector(*" << &v << ")\n";
    len = v.len;
    if(!len) { m = NULL; return ;}
    m = new T[len];
    for(int i = 0; i < len; i++) {
        m[i] = v.m[i];
    }
}

template<class T>
Kvector<T>::~Kvector<T>() {
        // cout << this << " : ~Kvector() \n";
        delete[] m;
}

template<class T>
Kvector<T>& Kvector<T>::operator=(const Kvector<T> &a) {
    cout << "Kvetor::operator= " << &a << '\n';
    if(this != &a) {
        delete[] m;
        len = a.len;
        m = new T[len];
        for(int i = 0; i < len; i++) {
            m[i] = a.m[i];
        }
    }
    return *this;
}
template<class T>
bool operator==(const Kvector<T> &a, const Kvector<T> &b) {
    if(a.len == b.len) {
        for(int i = 0; i < a.len; i++) {
            if(a.m[i] != b.m[i]) return false;
        }
        return true;
    }
    return false;
}
template<class T>
bool operator!=(const Kvector<T> &a, const Kvector<T> &b) {
    return !(a == b);
}
template<class T>
ostream& operator<<(ostream& os, const Kvector<T> &a) {
    for(int i = 0; i < a.len; i++) {
        os << a.m[i] << ' ';
    }
    return os;
}

#endif