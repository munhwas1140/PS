#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
int a[22];
int dp[22][10001];
int go(int idx, int val) {
    if(val == 0) return 1;
    if(idx == 0 || val < 0) return 0;

    int &ret = dp[idx][val];
    if(ret != -1) return ret;

    ret = go(idx - 1, val);
    ret += go(idx, val - a[idx]);
    return ret;
}
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> m;

    memset(dp,-1,sizeof(dp));
    cout << go(n, m) << '\n';
    return ;
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}