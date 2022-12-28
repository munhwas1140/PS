#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
void solve() {
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
    vector<vector<pii>> dp(n + 1, vector<pii>(m + 1, {0, 1e9}));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int msz = min(dp[i][j-1].first, dp[i-1][j].first);
            int mv = min({dp[i-1][j].second, dp[i][j-1].second, a[i][j]});
            if(mv >= msz + 1) {
                int x = i - msz;
                int y = j - msz;
                if(x >= 1 && y >= 1 && a[x][y] >= msz + 1) {
                    dp[i][j] = {msz + 1, min(mv, a[x][y])};
                } else {
                    dp[i][j] = {msz, mv};
                }
            } else {
                dp[i][j] = {mv, max(mv, a[i][j])};
            }
            ans = max(ans, dp[i][j].first);
        }
    }

    cout << ans << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}