#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int a[101][101];
int dp[101][101];
int n;
int go(int x, int y) {
    if(x == n - 1) {
        return a[x][y];
    }
    int &ret = dp[x][y];
    if(ret != -1) return ret;

    ret = max(go(x + 1, y), go(x + 1 , y + 1)) + a[x][y];
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
    cout << go(0, 0) << '\n';
    return ;
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}