#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m, mod;
int a[333];
int dp[333][333];
int main() {
    fastio;
    cin >> n >> m >> mod;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    for(int i = 0; i < 333; i++) {
        for(int j = 0; j < 333; j++) {
            dp[i][j] = -1e9;
        }
    }
    dp[0][0] = 0;

    for(int i = 1; i <= m; i++) {
        for(int j = 0; j < mod; j++) {
            for(int x = 1; x <= n; x++) {
                dp[i][(j + a[x]) % mod] = max(dp[i][(j + a[x]) % mod] , dp[i - 1][j] + a[x]);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i <= m; i++) {
        ans = max(ans, dp[i][0]);
    }
    cout << ans << '\n';

    return 0;
}