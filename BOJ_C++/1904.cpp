#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int mod = 15746;
int dp[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] %= mod;
    }
    cout << dp[n] << '\n';

    return 0;
}