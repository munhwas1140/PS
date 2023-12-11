#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> dp(n, -1);
    vector<bool> visited(n);
    while(m--) {
        int t1, t2;
        cin >> t1 >> t2;
        t1--; t2--;
        g[t1].push_back(t2);
    }

    function<int(int)> go = [&] (int now) {
        int &ret = dp[now];
        if(ret != -1) return ret;
        visited[now] = true;
        ret = 1;
        for(int &next : g[now]) {
            if(visited[next]) {
                ret &= 0;
                continue;
            }
            ret &= go(next);
        }
        return ret;
    };

    for(int i = 0; i < n; i++) {
        if(dp[i] != -1) continue;
        go(i);
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += dp[i];
    }
    cout << ans << '\n';
    return 0;
}