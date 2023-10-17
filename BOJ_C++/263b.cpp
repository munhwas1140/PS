#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
int main() {
    fastio;
    int n; cin >> n;
    vector<int> p(n + 1);
    vector<int> dp(n + 1);
    for(int i = 2; i <= n; i++) {
        cin >> p[i];
    }

    for(int i = 2; i <= n; i++) {
        dp[i] = dp[p[i]] + 1;
    }

    cout << dp[n] << '\n';
    return 0;
}