#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;


int main() {
    fastio;
    int n;
    cin >> n;
    int num = 0;

    while(n--) {
        string op;
        int x;
        cin >> op;
        if(op == "add") {
            cin >> x;
            num |= (1<<x);
        } else if(op == "remove") {
            cin >> x;
            num &= ~(1<<x);
        } else if(op == "check") {
            cin >> x;
            cout << ((num & (1<<x)) ? 1 : 0) << '\n';
        } else if(op == "toggle") {
            cin >> x;
            num ^= (1 << x);
        } else if(op == "all") {
            num = (1 << 21) - 1;
        } else if(op == "empty") {
            num = 0;
        }
    }     
      
    return 0;
}