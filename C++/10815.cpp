#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    set<int> st;
    for(int i = 0; i < n; i++) {
        int t; cin >> t;
        st.insert(t);
    }
    int m; cin >> m;
    for(int i = 0; i < m; i++) {
        int t; cin >> t;
        cout << st.count(t) << ' ';
    }
    return 0;
}