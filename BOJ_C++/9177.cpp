#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
string a, b, c;
int n, m, k;
int dp[201][201];
int go(int x, int y) {
    int z = x + y;
    if(z == k) {
        return 1;
    }

    int &ret = dp[x][y];
    if(ret != -1) return ret;
    ret = 0;

    if(x < n && c[z] == a[x]) {
        ret |= go(x + 1, y);
    }
    if(y < m && c[z] == b[y]) {
        ret |= go(x, y + 1);
    }

    return ret;
}

bool solve() {
    cin >> a >> b >> c;
    n = a.size();
    m = b.size();
    k = n + m;
    memset(dp,-1,sizeof(dp));
    return go(0,0);
}
int main() {
    fastio;
    int tc; cin >> tc;
    for(int TC = 1; TC <= tc; TC++) {
        bool ans = solve();
        cout << "Data set " << TC << ": ";
        cout << (ans ? "yes" : "no") << '\n';
    }
    return 0;
}