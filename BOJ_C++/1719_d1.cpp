#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), dp(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] ^= a[i - 1];
    }

    for(int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        for(int j = 0; j < i; j++) {
            if(a[j] == a[i]) dp[i] = min(dp[i], dp[j] + i - j - 1);
        }
    }
    cout << dp[n] << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}