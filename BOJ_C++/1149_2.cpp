#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
int a[1001][3];
int dp[1001][3][3];
int go(int idx, int now, int st) {
    if(idx == n + 1) {
        if(now == st) return 1e9;
        return 0;
    }

    int &ret = dp[idx][now][st];
    if(ret != -1) return ret;

    ret = min(go(idx + 1, (now + 1) % 3, st), go(idx + 1, (now + 2) % 3, st)) + a[idx][now];
    return ret;
}
int main() {
    fastio;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }

    memset(dp,-1,sizeof(dp));
    cout << min({go(1,0,0), go(1,1,1), go(1,2,2)}) << '\n';

    return 0;
}