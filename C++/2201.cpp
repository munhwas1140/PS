#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
ll LMAX = 1'000'000'000'000'000'000;
ll dp[200];
ll go(int now) {
    if(now == 1 || now == 2) return ll(now);
    
    ll &ret = dp[now];
    if(ret != -1) return ret;
    return ret = go(now - 1) + go(now - 2);
}
void trace(int now, ll k) {
    if(now == 0) return ;
    if(go(now) <= k) {
        cout << 1;
        trace(now - 1, k - go(now));
    } else  {
        cout << 0;
        trace(now - 1, k);
    }
}
int main() {
    fastio;
    ll k; cin >> k;
    memset(dp,-1,sizeof(dp));
    for(int i = 2; ;i++) {
        if(k < go(i)) {
            trace(i - 1, k);
            break;
        }
    }
    return 0;
}