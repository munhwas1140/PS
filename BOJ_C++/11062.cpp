#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int a[1001];
int dp[1001][1001];
int go(int s, int e, int turn) {
    if(s == e) {
        return turn ? a[s] : 0;
    }

    int &ret = dp[s][e];
    if(ret != -1) return ret;
    if(turn) {
        ret = max(a[s] + go(s + 1, e, 0), a[e] + go(s, e - 1, 0));
    } else {
        ret = min(go(s + 1, e, 1), go(s, e - 1, 1));
    }
    return ret;
}
void solve() {
    int n; cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    memset(dp,-1,sizeof(dp));
    int ans = go(0, n - 1, 1);
    cout << ans << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}