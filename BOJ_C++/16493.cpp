#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
int w[21], v[21];
int dp[201];
int main() {
    fastio;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> w[i] >> v[i];
    }
    
    memset(dp,-1,sizeof(dp));
    dp[0] = 0;
    for(int i = 1; i <= m; i++) {
        for(int j = n; j >= w[i]; j--) {
            if(dp[j - w[i]] != -1) {
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';

    return 0;
}