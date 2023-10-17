#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dp[101];
const int mod = 1e9 + 7;
int go(int now) {
    if(now <= 1) return 1;

    int &ret = dp[now];
    if(ret != -1) return ret;
    return ret = (go(now - 1) + go(now - 2)) % mod;
}
void solve() {
    int n; cin >> n;
    if(n % 2 == 1) {
        cout << (go(n) - go(n / 2) + mod) % mod << '\n';
    } else {
        int ret = go(n);
        ret = (ret - go(n / 2) + mod) % mod;
        ret = (ret - go((n / 2) - 1) + mod) % mod;
        cout << ret << '\n';
    }
}
int main() {
    fastio;
    int tc; cin >> tc;
    memset(dp,-1,sizeof(dp));
    while(tc--) {
        solve();
    }

    return 0;
}