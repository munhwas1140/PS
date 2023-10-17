#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
ll dp[101][100001];
int w[101], v[101];
int n, k;
ll go(int idx, int val) {
    if(val <= 0) return 0LL;
    if(idx < 0) return 1LL << 60;
    ll &ret = dp[idx][val];
    if(ret != -1) return ret;
    return ret = min(go(idx - 1, val), go(idx - 1, val - v[idx]) + w[idx]);
}
int main() {
    fastio;
    memset(dp,-1,sizeof(dp));
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    
    int ans = 0;
    for(int i = 1; i <= 100'000; i++) {
        if(go(n - 1, i) <= k) ans = i;
        else break;
    }
    cout << ans << '\n';
    return 0;
}