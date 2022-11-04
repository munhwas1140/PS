#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, l, r;
const int MOD = 1e9 + 7;
ll dp[101][101][101];
int go(int n, int l, int r) {
    if(n == 1) return (l == 1 && r == 1);

    ll &ret = dp[n][l][r];
    if(ret != -1) return ret;

    ret = 0;
    ret = go(n - 1, l - 1, r) + go(n - 1, l, r - 1) + go(n - 1, l, r) * (n - 2);
    ret %= MOD;
    return ret;

}
int main() {
    fastio;
    cin >> n >> l >> r;
    
    memset(dp,-1,sizeof(dp));
    cout << go(n, l, r) << '\n';
    return 0;
}