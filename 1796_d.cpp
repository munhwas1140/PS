#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
ll dp[200001][21][3];
void solve() {
    int n, k;
    ll x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            for(int x = 0; x < 3; x++) {
                dp[i][j][x] = -2e18;
            }
        }
    }

    dp[0][0][0] = 0LL;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= k; j++) {
            for(int t = 0; t < 3; t++) {
                if(dp[i][j][t] == -2e18) continue;
                for(int tt = t; tt < 3; tt++) {
                    dp[]
                }

                if(j + 1 <= k) {
                    for(int tt = t; tt < 3; tt++) {

                    }
                }
            }
        }
    }
    cout << max(dp[n][k][1], dp[n][k][2]) << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}