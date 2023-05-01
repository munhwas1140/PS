#include <iostream>
#include <cstring>
using namespace std;
#define NAME_LEN 100

class Student { 
    int id;
    char *name;
public:
    Student(int n, const char *s) {
        id = n;
        name = new char[NAME_LEN];
        strncpy(name, s, NAME_LEN);
        name[NAME_LEN - 1] = '\0';
    }
    ~Student() { delete[] name;}
    Student(const Student &st) {
        // 디폴트 복사 생성자는 무조건 shallow copy
        // 멤버변수에 포인터변수 있으면 조심
        id = st.id;
        //  name = st.name; shallow copy
        name = new char[NAME_LEN];
        strncpy(name, st.name, NAME_LEN);
        name[NAME_LEN - 1] = '\0';
        // deep copy
    }
    void setName(const char *s) {
        strncpy(name, s, NAME_LEN);
        name[NAME_LEN - 1] = '\0';
    }
    void print() {
        cout << this << " ] ";
        cout << " id : " << id << " name : " << name << '\n';
    }
};

int main() {
    Student s1(20100001, "Kim"), s2(s1);
    s1.print(); s2.print();
    s2.setName("Park");
    s1.print(); s2.print();
}
