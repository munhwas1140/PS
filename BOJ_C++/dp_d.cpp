#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
ll dp[101][100001];
int w[101], v[101];
ll go(int idx, int wei) {
    if(idx < 0 || wei <= 0) return 0LL;
    
    ll &ret = dp[idx][wei];
    if(ret != -1) return ret;

    ret = go(idx - 1, wei);
    if(wei >= w[idx]) ret = max(ret, go(idx - 1, wei - w[idx]) + v[idx]);
    return ret;
}
int main() {
    fastio;
    memset(dp,-1,sizeof(dp));
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    cout << go(n - 1, k) << '\n';
    return 0;
}