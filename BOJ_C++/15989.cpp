#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
ll dp[10001][4];
int main() {
    fastio;
    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 2;
    dp[3][2] = 0;
    dp[3][3] = 1;

    for(int i = 4; i <= 10000; i++) {
        dp[i][1] = dp[i-1][1] + dp[i-1][2] + dp[i-1][3];
        dp[i][2] = dp[i-2][2] + dp[i-2][3];
        dp[i][3] = dp[i-3][3];
    }
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        cout << dp[n][1] + dp[n][2] + dp[n][3] << '\n';
    }
    return 0;
}