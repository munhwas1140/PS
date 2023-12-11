#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
string a, b, c;
int n, m, k;
int dp[101][101][101];

int go(int x, int y, int z) {
    if(x < 0 || y < 0 || z < 0) return 0;

    int &ret = dp[x][y][z];
    if(ret != -1) return ret;

    ret = max({go(x - 1, y, z), go(x, y - 1, z), go(x, y, z - 1)});
    if(a[x] == b[y] && b[y] == c[z]) return ret = go(x - 1, y - 1, z - 1) + 1;
    
    return ret;
}
int main() {
    fastio;
    cin >> a >> b >> c;
    n = a.size();
    m = b.size();
    k = c.size();

    memset(dp,-1,sizeof(dp));
    cout << go(n - 1, m - 1, k - 1) << '\n';

    return 0;
}