#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, a[30][30];
long long dp[30][30];
int dx[] = {0, -1};
int dy[] = {-1, 0};
ll go(int x, int y) {
    if(x < 0 || y < 0) return 0LL;

    ll &ret = dp[x][y];
    if(ret != -1) return ret;

    if(a[x][y]) ret = 1LL << 2 * (n - 1) - x - y;
    else ret = 0LL;
    ret += max(go(x - 1, y), go(x, y - 1));
    return ret;
}
int main() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << go(n - 1, n - 1) << '\n';
    return 0;
}
