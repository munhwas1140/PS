#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    stack<int> st;
    while(tc--) {
        string op; int t;
        cin >> op;

        if(op == "push") {
            cin >> t;
            st.push(t);
        } else if(op == "pop") {
            if(st.empty()) {
                cout << -1 << '\n';
            } else {
                cout << st.top() << '\n';
                st.pop();
            }
        } else if(op == "size") {
            cout << st.size() << '\n';
        } else if(op == "empty") {
            cout << st.empty() << '\n';
        } else {
            if(st.empty()) cout << -1 << '\n';
            else cout << st.top() << '\n';
        }
    }     
    return 0;
}