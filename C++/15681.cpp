#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, r, q;
int main() {
    fastio;

    cin >> n >> r >> q;
    vector<vector<int>> g(n + 1);
    vector<vector<int>> gg(n + 1);
    vector<int> sz(n + 1);

    for(int i = 0; i < n - 1; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }

    function<int(int, int)> dfs = [&] (int now, int p) {
        sz[now] = 1;
        for(int &next : g[now]) {
            if(next == p) continue;
            gg[now].push_back(next);
            sz[now] += dfs(next, now);
        }
        return sz[now];
    };

    dfs(r, -1);

    
    while(q--) {
        int x; cin >> x;
        int ans = 0;
        for(int next : gg[x]) {
            ans += sz[next];
        }
        cout << ans + 1 << '\n';
    }

    return 0;
}