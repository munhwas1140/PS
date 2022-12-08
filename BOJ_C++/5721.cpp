#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
vector<vector<int>> dp, a;
int go(int x, int y) {
    int &ret = dp[x][y];
    if(ret != -1) return ret;
    ret = a[x][y];
    
    for(int next = y + 2; next < min(m, y + 4); next++) {
        ret = max(ret, go(x, next) + a[x][y]);
    }

    for(int next = x + 2; next < min(n, x + 4); next++) {
        ret = max(ret, go(next, 0) + a[x][y]);
        if(m >= 1) {
            ret = max(ret, go(next, 1) + a[x][y]);
        }
    }
    return ret;
}
void solve() {
    dp = vector<vector<int>>(n, vector<int>(m, -1));
    a = vector<vector<int>>(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    
    int ans = -1;
    for(int i = 0; i < min(n, 2); i++) {
        ans = max(ans, go(i,0));
        if(m >= 2) {
            ans = max(ans, go(i, 1));
        }
    }

    cout << ans << '\n';
}
int main() {
    fastio;
    while(true) {
        cin >> n >> m;
        if(!n && !m) break;
        solve();
    }

    return 0;
}