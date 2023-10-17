#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
vector<vector<int>> dp;
vector<vector<int>> a;

int go(int val, int x, int y) {
    if(a[x][y] < val) return 0;

    int &ret = dp[x][y];
    if(ret != -1) return ret;
    ret = 1;

    if(x + 1 < n && y + 1 < m) {
        ret = min({go(val, x + 1, y), go(val, x, y + 1), go(val, x + 1, y + 1)}) + 1;
    }
    return ret;

}

void solve() {
    cin >> n >> m;
    vector<vector<int>> tmp(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> tmp[i][j];
        }
    }

    a = tmp;

    int s = 1, e = min(n, m);
    int ans = 0;
    while(s <= e) {
        int k = (s + e) / 2;
        vector<vector<int>> t(n, vector<int>(m, -1));

        dp = t;
        int ret = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ret = max(ret, go(k, i, j));
            }
        }

        if(ret >= k) {
            ans = k;
            s = k + 1;
        } else e = k - 1;
    }
    cout << ans << '\n';
}

int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}