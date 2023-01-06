#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() { 
    int n; cin >> n;
    string str; cin >> str;
    set<string> st;
    for(int i = 0; i < n - 1; i++) {
        if(i > 1) {
            string tt(str.begin() + i - 2, str.begin() +i);
            st.insert(tt);
        }
        string tmp(str.begin() + i, str.begin() + i + 2);
        if(st.count(tmp)) {
            cout << "YES" << '\n';
            return ;
        }
    }
    cout << "NO" << '\n';
    return ;
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}