#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9 + 7;
ll dp[100001][5];
int main() {
    fastio;

    int n; cin >> n;
    dp[1][0] = 25LL;
    dp[1][1] = 1LL;
    for(int i = 2; i <= n; i++) {
        dp[i][0] = (dp[i - 1][0] * 25LL) % MOD;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][1] * 25LL) % MOD;
        dp[i][2] = (dp[i - 1][1] + dp[i - 1][2] * 25LL) % MOD;
        dp[i][3] = (dp[i - 1][2] + dp[i - 1][3] * 25LL) % MOD;
        dp[i][4] = (dp[i - 1][3] + dp[i - 1][4] * 26LL) % MOD;
    }

    cout << dp[n][4] << '\n';
    return 0;
}
