#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9;
int main() {
    fastio;
    int n; cin >> n;
    vector<ll> dp(1000001);
    dp[1] = 0;
    dp[2] = 1;
    for(int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] * (i - 1);
        dp[i] %= MOD;
        dp[i] += (i - 1) * dp[i - 2];
        dp[i] %= MOD;
    }

    cout << dp[n] << '\n';
    
    return 0;
}