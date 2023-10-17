#include <bits/stdc++.h>
using namespace std;
class Car{
    string color;
    int speed;
    int serial;
public:
    static int numberOfCars;
    Car(int s = 0, string c = "white") : speed(s), color(c) {
        serial = ++numberOfCars;
    }

    static int getNumberOfCars() { return numberOfCars;}
    // 객체 없이 호출 가능 (있어도 가능)
    // instance member variable, function 을 호출할 수 없다.

    void display() const {
        speed = 10; // 컴파일 에러
        // const  member function 이기 때문에 불가능 
        // const object 에 대해서는 const member function만 호출 가능
        // member 변수의 값을 바꾸지 않더라고 const function 아니면
        // 호출 불가
        cout << this << " ] " << serial << ", ";
        cout << speed << ", " << color << '\n';
    }

    // const 수식어도 function signature에 포함->함수 overloading 가능
    void display() {
        cout << this << " ] " << serial << ", ";
        cout << speed << ", " << color << '\n';
    }


    
};
int Car::numberOfCars = 0;
// static member variable의 초기화는 class밖에서 해주어야 함
// 이 변수는 클래스의 객체가 없어도 존재함

void swapObjects(Car &c1, Car &c2) {
    Car tmp;
    tmp = c1;
    c1 = c2;
    c2 = tmp;
}

Car buyCar(string color) {
    Car tmp(30, color);
    tmp.display();
    return tmp;
}


int main() {
    // swap!
    // Car redCar(100, "red"), blueCar(50, "blue");
    // redCar.display(); blueCar.display();
    // swapObjects(redCar, blueCar);
    // redCar.display(); blueCar.display();
    

    // buyCar
    // Car myCar;
    // myCar.display();
    // myCar = buyCar("green");
    // myCar.display();

    // dafault assignment operator
    Car carArray[2] = {
        Car(100, "red"), Car(50,"blue")
    };
    for(int i = 0; i < 2; i++) {
        carArray[i].display();
    }
    cout << "sizeof(Car) = " << sizeof(Car) << '\n';
    Car *ptr = new Car[3];
    ptr->display();
    (ptr + 1)->display();
    *ptr = carArray[0];
    ptr->display();
    
    return 0;
}