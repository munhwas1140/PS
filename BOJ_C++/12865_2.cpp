#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int w[101];
int v[101];
int dp[101][100001];

int go(int x, int y) {
    if(y < 0) return -1e9;
    if(x == 0) return 0;

    int &ret = dp[x][y];
    if(ret != -1) return ret;
    ret = go(x - 1, y);
    ret = max(ret, go(x - 1, y - w[x]) + v[x]);
    return ret;
}
int main() {
    fastio;
    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }

    memset(dp,-1,sizeof(dp));
    cout << go(n, k) << '\n';
    return 0;
}