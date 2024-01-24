#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    string a, b, c;
    cin >> a >> b >> c;
    bool f = false;
    for(int i = 0; i < n; i++) {
        if(a[i] == b[i]) {
            if(a[i] != c[i]) {
                f = true;
            }
        } else {
            if(a[i] != c[i] && b[i] != c[i]) {
                f = true;
            }
        }
    }

    if(f) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}