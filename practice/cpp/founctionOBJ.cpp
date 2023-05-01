#include <bits/stdc++.h>
using namespace std;
class Cmp{
public:
    bool operator()(int &a, int &b) {
        return a % 3 < b % 3;
    }    
};
int main() {
    int i;
    priority_queue<int, vector<int>, Cmp> pq;

    for(int i = 0; i < 9; i++) pq.push(i);
    while(!pq.empty()) {
        cout << pq.top() << ' ';
        pq.pop();
    }
    cout << '\n';
    return 0; 
}