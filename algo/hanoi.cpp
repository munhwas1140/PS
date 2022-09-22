#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
int n;
stack<int> st[3];
void go(int n, int a, int b, int c) {
    if(n == 0) return;
    go(n - 1, a, c, b);
    st[c].push(st[a].top());
    st[a].pop();
    if(a == 2 || c == 2) {
        cout << (st[2].empty() ? 0 : st[2].top()) << ' ';
    }
    go(n - 1, b, a, c);
}
    
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i = 0; i < 3; i++) {
            while(!st[i].empty()) st[i].pop();
        }
        for(int i = n; i >= 1; i--) {
            st[0].push(i);
        }
        go(n, 0, 1, 2);
        cout << '\n';
    }

    return 0;
}