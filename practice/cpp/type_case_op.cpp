#include <bits/stdc++.h>
using namespace std;

class Book {
private: 
    int isbn;
    string title;
public:
    Book(int isbn, string &title) {
        this->isbn = isbn;
        this->title = title;
    }
    Book(int isbn) { // 변환 생성자 (int -> Book)
        this->isbn = isbn;
        this->title = "unknown";
    }
    operator int() const { //변환 연산자 (Book -> int)
        return isbn;
    }
    void display() {
        cout << isbn << ":" << title << '\n';
    }
};

bool check(int isbn) {
    cout << isbn << '\n';
    return true;
}

int main() {
    Book b1 = 9782001; // int->Book 변환 생성자
    b1.display();
    int isbn = b1;  // Book->int 변환 연산자
    cout << isbn << '\n';
    check(b1); // Book->int 변환 연산자
    
    return 0;
}