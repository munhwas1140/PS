#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
int a[2][100002];
int dp[2][100002];
void solve() {
    cin >> n;

    for(int i = 0; i < 2; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    int ans = 0;
    for(int j = 1; j <= n; j++) {
        for(int i = 0; i < 2; i++) {
            dp[i][j] = dp[i ^ 1][j - 1] + a[i][j];
            if(j >= 2) dp[i][j] = max(dp[i][j], dp[i ^ 1][j - 2] + a[i][j]);
            ans = max(ans, dp[i][j]);
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