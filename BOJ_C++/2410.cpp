#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
int n;
const int mod = 1e9;
int dp[1000001];
int main() {
    fastio;
    cin >> n;
    memset(dp,-1,sizeof(dp));
    dp[1] = 1;

    for(int i = 2; i <= n; i++) {
        if(i % 2) {
            dp[i] = dp[i-1];
        } else {
            dp[i] = dp[i-1] + dp[i / 2];
        }
        dp[i] %= mod;
    }
    cout << dp[n] << '\n';
    return 0;
}