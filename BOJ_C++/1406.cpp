#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    string str; cin >> str;
    stack<char, string> l(str), r;
    int q; cin >> q;
    while(q--) {
        char c; cin >> c;
        if(c == 'L') {
            if(!l.empty()) {
                r.push(l.top()); l.pop();
            }
        } else if(c == 'D') {
            if(!r.empty()) {
                l.push(r.top()); r.pop();
            }
        } else if(c == 'B') {
            if(!l.empty()) l.pop();
        } else if(c == 'P') {
            char v; cin >> v;
            l.push(v);
        }
    }

    while(!l.empty()) {
        r.push(l.top()); l.pop();
    }

    while(!r.empty()) {
        cout << r.top();
        r.pop();
    }

    return 0;
}