#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
const int MOD = 1e9 + 7;
string a[1001];
int dp[1001][1001];
int go(int x, int y) {
    if(x == 0 && y == 0) return 1;
    
    int &ret = dp[x][y];
    if(ret != -1) return ret;

    ret = 0;
    if(x - 1 >= 0 && a[x - 1][y] == '.') ret += go(x - 1, y);
    if(y - 1 >= 0 && a[x][y - 1] == '.') ret += go(x, y - 1);
    ret %= MOD;
    return ret;
}
int main() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    memset(dp,-1,sizeof(dp));
    cout << go(n - 1, m - 1) << '\n';
    return 0;
}