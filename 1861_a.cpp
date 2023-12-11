#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    string str;
    cin >> str;
    for(auto c : str) {
        if(c == '7') {
            cout << 71 << '\n';
            return ;
        } else if(c == '1') {
            cout << 17 << '\n';
            return ;
        }
    }
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}