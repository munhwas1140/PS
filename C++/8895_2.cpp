#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
ll dp[21][21][21];
ll comb[21][21];
ll go(int n, int l, int r) {
    if(n == 1 && l == 1 && r == 1) return 1LL;
    
    ll &ret = dp[n][l][r];
    if(ret != -1) return ret;
    ret = go(n - 1, l, r) * (ll)(n - 2);

    if(l >= 2) {
        ret += go(n - 1, l - 1, r);
    }
    if(r >= 2) {
        ret += go(n - 1, l, r - 1);
    }
    return ret;
}
void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    cout << go(n, l, r) << '\n';
}
int main() {
    fastio;
    memset(dp,-1,sizeof(dp));

    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}