#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    stack<int> st;
    for(int i = 0; i < n; i++) {
        int q; cin >> q;
        if(q == 1) {
            int num; cin >> num;
            st.push(num);
        } else if(q == 2) {
            if(st.empty()) cout << -1 << '\n';
            else {
                int now = st.top();
                st.pop();
                cout << now << '\n';
            }
        } else if(q == 3) {
            cout << (int)st.size() << '\n';
        } else if(q == 4) {
            cout << (int)st.empty() << '\n';
        } else {
            if(st.empty()) cout << -1 << '\n';
            else cout << st.top() << '\n';
        }
    }
    return 0;
}