#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[1001][1001];
const int mod = 1e4 + 7;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;     

    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        dp[i][0] = 1;
        dp[i][i] = 1;
        for(int j = 1; j < i; j++) {
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            dp[i][j] %= mod;
        }
    }

    cout << dp[n][k] << '\n';

    return 0;
}