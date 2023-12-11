#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
int dp[100][100];
int a[100][100];
int go(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= n) return 0;
    if(x == n - 1 && y == n - 1) return 1;

    int &ret = dp[x][y];
    if(ret != -1) return ret;

    ret = (go(x + a[x][y], y) | go(x, y + a[x][y]));
    return ret;
}
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    memset(dp,-1,sizeof(dp));
    int ans = go(0,0);
    if(ans == 1) {
        cout << "YES" << '\n';
    } else cout << "NO" << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }

    return 0;
}