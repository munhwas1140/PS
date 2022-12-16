#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int k, n;
ll dp[21][211];
ll go(int idx, int sum) {
    if(idx == k) {
        return (ll)(sum == 0);
    }
    
    ll &ret = dp[idx][sum];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 0; i <= idx + 1; i++) {
        ret += go(idx + 1, sum - i);
    }
    return ret;
    
}
void solve() {
    memset(dp,-1,sizeof(dp));
    cin >> k >> n;
    cout << go(0,n) << '\n';
}
int main() {

    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}