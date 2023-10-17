#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int mod = 1e7;
int dp[101][101];
int go(int now, int first) {
    if(now == first) return 1;
    int &ret = dp[now][first];
    if(ret != -1) return ret;
    ret = 0;
    for(int next = 1; next <= now - first; next++) {
        ret += (first + next - 1) * go(now - first, next);
        ret %= mod;
    }
    return ret;
}
void solve() {
    int n; cin >> n;
    int ret = 0;
    for(int i = 1; i <= n; i++) {
        ret = (ret + go(n, i)) % mod;
    }
    cout << ret << '\n';
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