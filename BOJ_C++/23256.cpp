#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
ll dp[1000003][2];
const ll mod = 1e9 + 7;
void init() {
    dp[1][1] = 7;
    dp[1][0] = 3;
    
}
void solve() {
    int n; cin >> n;
    cout << go(n, 0) << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    memset(dp,-1,sizeof(dp));
    init();
    while(tc--) {
        solve();
    }
    return 0;
}