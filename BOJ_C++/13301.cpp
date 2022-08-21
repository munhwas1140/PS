#include <bits/stdc++.h>
using namespace std;
long long dp[81];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    if(n == 1) return !(cout << 4 << '\n');
    else if(n == 2) return !(cout << 6 << '\n');
    else if(n == 3) return !(cout << 10 << '\n');
    dp[1] = 1;
    dp[2] = 1;
    for(int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    long long ans = 0;
    ans += dp[n] * 3;
    ans += 2 * (dp[n-1] + dp[n-2]);
    ans += dp[n-3];
    cout << ans << '\n';

    return 0;
}