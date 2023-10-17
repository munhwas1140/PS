#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m, k;
int dp[101][101];
int go(int a, int z) {
    if(a == 0 || z == 0) return 1;
    int &ret = dp[a][z];
    if(ret != -1) return ret;
    ret = go(a - 1, z) + go(a, z - 1);
    if(ret > 1000000001) ret = 1000000001;
    return ret;
}
void trace(int a, int z, int k) {
    if(z == 0) {
        cout << string(a, 'a'); return;
    }
    if(a == 0) {
        cout << string(z, 'z'); return ;
    }

    int tmp = go(a - 1, z);
    if(k <= tmp) {
        cout << 'a';
        trace(a - 1, z, k);
    } else {
        cout << 'z';
        trace(a, z - 1, k - tmp);
    }
    return ;
}
int main() {
    fastio;
    cin >> n >> m >> k;
    memset(dp,-1,sizeof(dp));
    if(k > go(n, m)) return !(cout << -1 << '\n');
    trace(n, m, k);
    return 0;
}