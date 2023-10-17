#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int mod = 1e9 + 7;
int dp[1516][3];
int main() {
    fastio;
    int n; cin >> n;

    dp[2][0] = 1;
    dp[2][2] = 1;
    for(int i = 3; i <= n; i++) {
        dp[i][0] = (dp[i-1][1] + dp[i-1][2]) % mod;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % mod;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % mod;
    }
    cout << dp[n][0] << '\n';
    return 0;
}