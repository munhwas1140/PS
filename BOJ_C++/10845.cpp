#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    queue<int> q;
    while(tc--) {
        string op; int x;

        cin >> op;

        if(op == "push") {
            cin >> x;
            q.push(x);
        } else if(op == "pop") {
            if(q.empty()) cout << -1 << '\n';
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        } else if(op == "size") {
            cout << q.size() << '\n';
        } else if(op == "empty") {
            cout << q.empty() << '\n';
        } else if(op == "front") {
            if(q.empty()) cout << -1 << '\n';
            else cout << q.front() << '\n';
        } else if(op == "back") {
            if(q.empty()) cout << -1 << '\n';
            else cout << q.back() << '\n';
        }
    }    
      
    return 0;
}