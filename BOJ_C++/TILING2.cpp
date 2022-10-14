#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int mod = 1e9 + 7;
int dp[101];
int go(int now) {
    if(now == 0) return 1;
    int &ret = dp[now];
    if(ret != -1) return ret;
    ret = go(now - 1) + go(now - 2);
    ret %= mod;
    return ret;
}
void solve() {
    int n; cin >> n;
    cout << go(n) << '\n';
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