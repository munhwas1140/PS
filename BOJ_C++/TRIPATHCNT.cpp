#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
int a[101][101];
int dp[101][101];
int cntdp[101][101];
int go(int x, int y) {
    if(x == n - 1) return a[x][y];

    int &ret = dp[x][y];
    if(ret != -1) return ret;

    ret = 0;
    ret = max(go(x + 1, y), go (x + 1, y + 1)) + a[x][y];
    return ret;
}
int goCnt(int x, int y) {
    if(x == n - 1) return 1;

    int &ret = cntdp[x][y];
    if(ret != -1) return ret;
    ret = 0;
    int l = go(x + 1, y);
    int r = go(x + 1, y + 1);
    if(l <= r) ret += goCnt(x + 1, y + 1);
    if(l >= r) ret += goCnt(x + 1, y);
    return ret;
}
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cin >> a[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    memset(cntdp,-1,sizeof(cntdp));
    go(0, 0);
    cout << goCnt(0, 0) << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }

    return 0;
}   