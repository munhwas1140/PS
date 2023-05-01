#include <iostream>
#include <string>

class Team {
    std::string name;
    int wins;
public:
    Team(const std::string &n = "teamX", int w = 0) : name(n), wins(w) {}
    Team& operator+=(const Team &rhs) {
        wins += rhs.wins;
        return *this;
    }
    friend Team operator+(Team a, const Team &b) {
        a += b;
        return a;
    }
    friend bool operator==(const Team &a, const Team &b) {
        return (a.name == b.name);
    }
    friend bool operator!=(const Team & a, const Team &b) {
        return !(a == b);
    }
    friend std::ostream& operator<<(std::ostream &os, const Team &a) {
        os << a.name << "(" << a.wins << ")";
        return os;
    }
};