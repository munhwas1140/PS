#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

class MyString {
    char *p;
public:
    MyString(const char *str = nullptr);
    MyString(const MyString &s);
    ~MyString();
    friend ostream& operator<<(ostream& os, const MyString &s) {
        os << s.p;
        return os;
    }
    char& operator[](int idx) {assert(0 <= idx && idx < size());return this->p[idx];}
    const char& operator[](int idx) const {
        assert(0 <= idx && idx < size());
        return this->p[idx];
    }
    MyString& operator+=(const MyString &b);
    MyString& operator=(const MyString &s);
    friend MyString operator+(MyString a, const MyString &b);
    void print();
    int size() const;
};
MyString::MyString(const char *str) {
    if(!str) {
        p = new char[1];
        p[0] = '\0';
        return ;
    }
    p = new char[strlen(str) + 1];
    strcpy(p, str);
    cout << this << ' ' << str << "] MyString(const char *)\n";
}
MyString::MyString(MyString const &s) {
    p = new char[s.size() + 1];
    strcpy(p, s.p);
    cout << this << ' ' << s.p << "] MyString(const MyString &)\n";
}
MyString& MyString::operator+=(const MyString &b) {
    int len = size() + b.size() + 1;
    char *new_p = new char[len];
    strcpy(new_p,p);
    strcat(new_p, b.p);
    delete[] p;
    p = new_p;
    return *this;

    // strcat(this->p, b.p);
    // return *this;
}
MyString operator+(MyString a, const MyString &b) {
    a += b;
    return a;
}

MyString& MyString::operator=(const MyString &s) {
    if(&s != this) {
        delete[] p;
        int len = s.size() + 1;
        p = new char[len];
        strcpy(p, s.p);
    }
    return *this;
}

int MyString::size() const {
    return strlen(p);
}

MyString::~MyString() { delete[] p;}
void MyString::print() {
    cout << p << '\n';
}

int main() {
    char word[] = "aprill";
    const MyString m1("1st");
    MyString m2(word);
    MyString m3 = m1 + m2;
    cout << "m1: " << m1 << '\n';
    cout << "m2: " << m2 << '\n';
    cout << "m3: " << m3 << '\n';
    m2[1] = m1[0];
    cout << "m2: " << m2 << '\n';
    m2 += m1;
    cout << "m2: " << m2 << '\n';
    
    MyString a;
    char s[10] = "car";
    a = s; // a = tmp.MyString(s);
    return 0;
}