#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
int dp[100001];
vector<int> g[100001];
int go(int now) {
    int &ret = dp[now];
    if(ret != -1) return ret;
    ret = 0;
    for(int &next : g[now]) {
        ret = max(go(next) + 1,ret);
    }
    return ret;
}
int main() {
    fastio;
    cin >> n >> m;
    
    for(int i = 1; i <= m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
    }

    memset(dp,-1,sizeof(dp));
    
    int ans = -1;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, go(i));
    }
    cout << ans << '\n';
    return 0;
}