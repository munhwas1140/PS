#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, l, k;
int dp[100001][11];
int a[100001];
int go(int idx, int now) {
    int &ret = dp[idx][now];
    if(ret != -1) return ret;
    
    if(idx == n) {
        if(now == k - 1) return ret = 0;
        else return ret = 1e9;
    }
    if(now > k - 1) return ret = 1e9;
    
    ret = 1e9;
    
    if(a[idx + 1] > a[idx]) {
        ret = min(ret, go(idx + 1, now + 1));

        int tmp = a[idx + 1];
        a[idx + 1] = a[l];
        ret = min(ret, go(idx + 1, now) + 1);
        a[idx + 1] = tmp;
    } else {
        return ret = go(idx + 1, now);
    }

    return ret;
}
int main() {
    fastio;
    cin >> n >> l >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int h = a[l];
    int ans = 0;
    for(int i = 1; i < l; i++) {
        if(a[i] >= h) ans++;
    }
    memset(dp,-1,sizeof(dp));


    go(l, 0);
    // for(int i = l; i <= n; i++) {
    //     for(int j = 0; j < k; j++) {
    //         cout << (dp[i][j] == 1e9 ? -1 : dp[i][j]) << ' ';
    //     }
    //     cout << '\n';
    // }

    ans = ans + go(l, 0);
    if(ans >= 1e9) {
        cout << -1 << '\n';
    } else cout << ans << '\n';
    return 0;
}