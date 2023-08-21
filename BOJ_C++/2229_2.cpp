#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int a[1010];
int dp[1010];
int n;
int go(int now) {
    if(now == n) return 0;

    int &ret = dp[now];
    if(ret != -1) return ret;
    ret = go(now + 1);

    int mx = a[now], mn = a[now];
    for(int i = now + 1; i < n; i++) {
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
        ret = max(ret, mx - mn + go(i + 1));
    }
    return ret;
}
int main() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    memset(dp,-1,sizeof(dp));
    cout << go(0) << '\n';
    return 0;
}