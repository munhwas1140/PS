#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
ll dp[21][21][21];
ll go(int n, int l, int r) {
    if(n == l + r - 1) return 1;
    ll &ret = dp[n][l][r];
    if(ret != -1) return ret;
    ret = go(n - 1, l, r) * (n - 2);
    if(l - 1 >= 1) {
        ret += go(n - 1, l - 1, r);
    }
    if(r - 1 >= 1) {
        ret += go(n - 1, l, r - 1);
    }
    return ret;
}
int main() {
    fastio;
    memset(dp,-1,sizeof(dp));
    int tc; cin >> tc;
    while(tc--) {
        int n, l, r;
        cin >> n >> l >> r;
        cout << go(n, l, r) << '\n';
    }

    return 0;
}