#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
string a, b;
int n, m;
int dp[1001][1001];
int go(int x, int y) {
    if(x < 0 || y < 0) return 0;

    int &ret = dp[x][y];
    if(ret != -1) return ret;
    ret = max(go(x - 1, y), go(x, y - 1));
    if(a[x] == b[y]) {
        ret = max(ret, go(x - 1, y - 1) + 1);
    }
    return ret;
}
int main() {
    fastio;
    cin >> a >> b;
    n = a.size(); m = b.size();

    memset(dp,-1,sizeof(dp));
    cout << go(n - 1, m - 1) << '\n';
    return 0;
}