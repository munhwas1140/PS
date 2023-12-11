#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    string str; cin >> str;
    int n = str.size();
    bool f = false;
    for(int i = 0; i < n - 1; i++) {
        if(str[i] != str[i + 1]) {
            f = true;
            break;
        }
    }

    if(f) cout << n - 1 << '\n';
    else cout << -1 << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}