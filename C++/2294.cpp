#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, k;
int a[100];
int dp[10001];
int go(int now) {
    if(now == 0) return 0;
    if(now < 0) return 1e9;

    int &ret = dp[now];
    if(ret != -1) return ret;
    ret = 1e9;
    for(int i = 0; i < n; i++) {
        ret = min(ret, go(now - a[i]) + 1);
    }
    return ret;
}
int main() {
    fastio;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    memset(dp,-1,sizeof(dp));
    int ans = go(k);
    if(ans == 1e9) cout << -1 << '\n';
    else cout << ans << '\n';
    return 0;
}