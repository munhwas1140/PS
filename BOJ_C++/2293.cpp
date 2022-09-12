#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
int dp[2][10001];
int main() {
    fastio;
    int n, k;
    cin >> n >> k;
    dp[0][0] = dp[1][0] = 1;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        int prev = (i % 2) ^ 1;
        for(int j = 1; j <= k; j++) {
            dp[i % 2][j] = dp[prev][j];
            if(j - tmp >= 0) dp[i % 2][j] += dp[i % 2][j - tmp];
        }
    }
    cout << dp[(n - 1) % 2][k] << '\n';
      
    return 0;
}