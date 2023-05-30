#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

void solve() {
    ll a; cin >> a;
    if(a % 10 == 0) cout << 1 << '\n';
    else cout << 0 << '\n';
}

int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}