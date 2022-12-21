#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1e9 + 7;
int n, pi, pj, vi, vj;
bool valid(int p, int v) {
    if(p == pi && v != vi) return false;
    if(p == pj && v != vj) return false;
    return true;
}
void solve() {
    cin >> n >> pi >> pj >> vi >> vj;
    --pi; --pj; --vi; --vj;
    vector<vector<int>> dp(n, vector<int>(n));
    for(int i = 1; i < n - 1; i++) {
        if(valid(i, n - 1)) {
            dp[i][i] = 1;
        }
    }

    for(int i = n - 1; i >= 0; i--) {
        for(int j = i; j < n; j++) {
            int val = n - 1 - (j - i + 1);
            if(i > 0) {
                if(valid(i - 1, val)) {
                    dp[i - 1][j] += dp[i][j];
                    dp[i - 1][j] %= MOD;
                }
            }
            if(j < n - 1) {
                if(valid(j + 1, val)) {
                    dp[i][j + 1] += dp[i][j];
                    dp[i][j + 1] %= MOD;
                }
            }
        }
    }
    cout << dp[0][n - 1] << '\n';
}
int main() {
    fastio;
    int tc;
    cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}