#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dp[2001][1001];
int w[1001], l[1001];
int n, m, k;
int go(int x, int y) {
    int &ret = dp[x][y];
    if(ret != -1) return ret;
    if(x != n) {
        ret = go(x + 1, y) + w[x];
    }
    if(y != m) {
        ret = max(ret, go(x, y + 1));
    }
    int w = go(x + 1, y );
    ret = go(x + 1, y), go(x, y + 1);

}
int main() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> w[i];
    cin >> m;
    for(int i = 0; i < m; i++) cin >> l[i];
    cin >> k;
    memset(dp, -1, sizeof(dp));
    cout << go(0, 0) << '\n';
    return 0;
}
