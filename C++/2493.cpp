#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    stack<pii> st;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        while(!st.empty()) {
           if(st.top().second <= tmp) st.pop();
           else break;
        }

        if(st.empty()) cout << 0 << ' ';
        else cout << st.top().first << ' ';

        st.push({i + 1, tmp});
    }
    cout << '\n';
    return 0;
}
