#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
int w[101], v[101];
ll dp[101][10001];
int main() {
    fastio;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    int ans = 10001;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= 10000; j++) {
            dp[i][j] = dp[i - 1][j];
            if(j >= w[i]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
            }
            if(dp[i][j] >= m) {
                ans = min(ans, j);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}