#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
int a[101];
int dp[101][101][2];
int go(int idx, int rem, int stat) {
    if(rem == 0) return 0;
    if(idx == n) return -1e9;

    int &ret = dp[idx][rem][stat];
    if(ret != -1) return ret;

    if(stat == 1) {
        ret = a[idx];
        ret += max(go(idx + 1, rem - 1, 0), go(idx + 1, rem, 1));
    } else {
        ret = 0;
        ret += max(go(idx + 1, rem, 1), go(idx + 1, rem, 0));
    }
    return ret;
}
int main() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    memset(dp,-1,sizeof(dp));
    cout << max(go(0, m, 0), go(0, m, 1)) << '\n';
    return 0;
}