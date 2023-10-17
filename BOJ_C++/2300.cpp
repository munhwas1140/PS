#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
int dp[10001];
pii a[10001];
int go(int now) {
    if(now == 0) return 0;

    int &ret = dp[now];
    if(ret != -1) return ret;
    ret = 1e9;

    int maxv = abs(a[now].second);
    
    for(int i = now; i >= 1; i--) {
        maxv = max(maxv, abs(a[i].second));

        ret = min(ret, go(i - 1) + max(a[now].first - a[i].first, maxv * 2));
    }
    return ret;
}
int main() {
    fastio;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + n + 1);
    memset(dp,-1,sizeof(dp));
    cout << go(n) << '\n';

    return 0;
}