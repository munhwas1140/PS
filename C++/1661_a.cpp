#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    vector<vector<ll>> a(2, vector<ll>(n));
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    ll ans = 0;
    for(int i = 0; i < n - 1; i++) {
        ll t1 = abs(a[0][i] - a[0][i + 1]) + abs(a[1][i] - a[1][i + 1]);
        ll t2 = abs(a[0][i] - a[1][i + 1]) + abs(a[1][i] - a[0][i + 1]);
        ans += min(t1, t2);
    }
    cout << ans << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}