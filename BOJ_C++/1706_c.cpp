#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if(n % 2 == 1) {
        ll ans = 0;
        for(int i = 1; i < n; i += 2) {
            ll tmp = max(a[i - 1], a[i + 1]);
            if(a[i] <= tmp) {
                ans += tmp + 1 - a[i];
            }
        }
        cout << ans << '\n';
    } else {
        vector<vector<ll>> dp(2, vector<ll>(n, -1));
        function<ll(int, int)> go = [&] (int state, int idx) {
            if(idx >= n - 1) return 0LL;
            ll &ret = dp[state][idx];
            if(ret != -1) return ret;
            ll tmp = max(a[idx - 1], a[idx + 1]);
            ret = max(0LL, tmp + 1 - a[idx]);
            ll t = 1e18;    
            if(state == 0) {
                t = min(t, go(1, idx + 3));
            }
            t = min(t, go(state, idx + 2));
            ret += t;
            return ret;
        };
        cout << min(go(0, 1), go(1, 2)) << '\n';
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