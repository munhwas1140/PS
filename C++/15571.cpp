#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dp[1000001];
const int MOD = 1999;
int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i - j >= 0) {
                dp[i] += dp[i - j];
                dp[i] %= MOD;
            }
        }
    }

    int nd = dp[n];
    dp[n] = (dp[n] * 2 - 1 + MOD) % MOD;

    for(int i = n + 1; i <= m; i++) {
        dp[i] = dp[i - n] * nd;
        for(int j = 1; j <= n - 1; j++) {
            dp[i] += dp[i - j];
            dp[i] %= MOD;
        }
        dp[i] %= MOD;
    }

    cout << dp[m] << '\n';
    return 0;
}