#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
int a[501];
int dp[501];
int go(int now) {
    int &ret = dp[now];
    if(ret != -1) return ret;
    ret = 1;
    for(int i = now + 1; i < n; i++) {
        if(a[now] < a[i]) {
            ret = max(ret, 1 + go(i));
        }
    }
    return ret;
}
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int maxlen = -1;
    memset(dp,-1,sizeof(dp));
    for(int i = 0; i < n; i++) {
        maxlen = max(maxlen, go(i));
    }
    cout << maxlen << '\n';
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