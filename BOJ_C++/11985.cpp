#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int main() {
    fastio;
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n + 1), dp(n + 1, 1e18);
    dp[0] = 0;
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++) {
        ll mx = a[i], mn = a[i];
        for(int j = i; j >= max(1, i - m + 1); j--) {
            mx = max(mx, a[j]);
            mn = min(mn, a[j]);
            dp[i] = min(dp[i], dp[j - 1] + k + (i - j + 1) * (mx - mn));
        }
    }
    cout << dp[n] << '\n';

    return 0;
}