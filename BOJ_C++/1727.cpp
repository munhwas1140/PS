#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
int diff;
int a[1001], b[1001];
int dp[1001][1001];
int go(int x, int y) {
    if(x == n || y == m) return 0;

    int &ret = dp[x][y];
    if(ret != -1) return ret;
    ret = 1e9;

    if(abs(x - y) < diff) {
        if(n > m) {
            ret = go(x + 1, y);
        } else {
            ret = go(x, y + 1);
        }
    } 

    ret = min(ret, go(x + 1, y + 1) + abs(a[x] - b[y]));
    return ret;
}
int main() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);
    memset(dp,-1,sizeof(dp));

    diff = abs(n - m);
    cout << go(0, 0) << '\n';
    return 0;
}