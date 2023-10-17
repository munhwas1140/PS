#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dp[500][500];
pii a[500];
int go(int s, int e) {
    if(s == e) return 0;
    int &ret = dp[s][e];
    if(ret != -1) return ret;
    ret = INT_MAX;
    for(int i = s; i < e; i++) {
        ret = min(ret, go(s, i) + go(i + 1, e) + a[s].first * a[i].second * a[e].second);
    }
    return ret;
}
int main() {
    fastio;
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    memset(dp,-1,sizeof(dp));
    cout << go(0, n - 1) << '\n';

    return 0;
}