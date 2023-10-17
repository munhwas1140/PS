#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
int w[5001], v[5001];
int dp[10001];
int main() {
    fastio;
    while(true) {
        double tmp;
        cin >> n >> tmp;
        m = int(tmp * 100.0 + 0.5);
        if(n == 0 && m == 0) break;

        for(int i = 1; i <= n; i++) {
            cin >> v[i] >> tmp;
            w[i] = int(tmp * 100.0 + 0.5);
        }

        memset(dp,-1,sizeof(dp));
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = w[i]; j <= m; j++) {
                dp[j] = max(dp[j], dp[j -  w[i]] + v[i]);
            }
        }

        int ans = 0;
        for(int i = 0; i <= m; i++) {
            ans = max(ans, dp[i]);
        }
        cout << ans << '\n';
    }
    return 0;
}