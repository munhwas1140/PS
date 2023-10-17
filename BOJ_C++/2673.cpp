#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int a[101];
int dp[101][101];
int go(int x, int y) {
    if(x >= y) return 0;
    int &ret = dp[x][y];
    if(ret != -1) return ret;

    ret = 0;
    for(int i = x; i <= y ; i++) {
        ret = max(ret, go(x, i) + go(i + 1, y));
    }
    if(a[x] == y) ret++;
    return ret;
}
int main() {
    fastio;

    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        a[t1] = t2;
        a[t2] = t1;
    }

    memset(dp,-1,sizeof(dp));
    cout << go(1, 100) << '\n';

    return 0;
}