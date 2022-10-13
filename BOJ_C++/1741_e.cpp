#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    vector<int> b(n + 1);
    vector<bool> dp(n + 1);
    for(int i = 1; i <= n; i++) cin >> b[i];
    dp[0] = true;
    for(int i = 1; i <= n; i++) {
        if(i + b[i] <= n && dp[i - 1]) dp[i + b[i]] = true;
        if(i - b[i] - 1 >= 0 && dp[i - b[i] - 1]) dp[i] = true;
    }
    cout << (dp[n] ? "YES" : "NO") << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }

    return 0;
}