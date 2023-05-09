#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

using mt = vector<vector<ll>>;
const ll MOD = 1e8 + 7;

mt mul(mt a, mt b) {
    vector<vector<ll>> tmp(2, vector<ll>(2, 0));
    for(int k = 0; k < 2; k++) {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                tmp[i][j] += a[i][k] * b[k][j];
                tmp[i][j] %= MOD;
            }
        }
    }
    return tmp;
}

mt pow(mt a, int k) {
    if(k <= 1) return a;
    else if(k % 2) {
        mt tmp = pow(a, k - 1);
        tmp = mul(tmp, a);
        return tmp;
    } else {
        mt tmp = pow(a, k / 2);
        tmp = mul(tmp, tmp);
        return tmp;
    }
}

void solve() {
    int k, n;
    cin >> k >> n;
    if(n <= k) cout << 1 << '\n';
    else {
        vector<vector<ll>> a(2, vector<ll>(2, 1));
        a[1][1] = 0;
        mt ret = pow(a, n - k);
        cout << (ret[1][0] + ret[1][1]) % MOD << '\n';
    }
    // dp[i] = dp[i - 1] + dp[i - k - 1];

    // dp[i + 1]         1 1 dp[i - 1]
    // dp[i]             1 0 dp[i - k - 1];
    
    // dp[i]           dp[i - 2]
    // dp[i - 1]       dp[i - k - 2]

    // dp[
    // dp[n - k k + 1]      (1, 1)^(n - k) dp[k]
    // dp[k]                (1, 0)         dp[0]
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}