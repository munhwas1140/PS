#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
pii a[500];
int dp[501][501];
int n, k;
int go(int now, int r) {

    if(now == n - 1) return 0;

    int &ret = dp[now][r];
    if(ret != -1) return ret;
    ret = 1e9;
    for(int i = 0; i <= r && now + i + 1 <= n - 1; i++) {
        ret = min(ret, abs(a[now].first - a[now + i + 1].first) + abs(a[now].second - a[now + i + 1].second) + go(now + i + 1, r - i));
    }

    return ret;
}
int main() {
    fastio;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    memset(dp,-1,sizeof(dp));
    cout << go(0, k) << '\n';
    return 0;
}