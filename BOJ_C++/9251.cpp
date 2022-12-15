#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
string a, b;
int n, m;
int dp[1010][1010];
int go(int x, int y) {
    if(x < 0 || y < 0) return 0;
    int &ret = dp[x][y];
    if(ret != -1) return ret;

    if(a[x] == b[y]) {
        ret = go(x - 1, y - 1) + 1;
    } else {
        ret = max(go(x - 1, y), go(x, y - 1));
    }
    return ret;
}
void trace(int x, int y) {
    if(x < 0 || y < 0) return;
    if(go(x, y) == go(x - 1, y)) {
        trace(x - 1, y);
    } else if (go(x, y) == go(x, y - 1)) {
        trace(x, y - 1);
    } else {
        trace(x - 1, y - 1);
        cout << a[x];
    }
}
int main() {
    fastio;
    cin >> a >> b;
    n = a.size();
    m = b.size();
    memset(dp,-1,sizeof(dp));
    cout << go(n - 1, m - 1) << '\n';

    trace(n - 1, m - 1);
    return 0;
}