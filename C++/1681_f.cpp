#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<vector<pii>> adj(n);

    for(int i = 0; i < n - 1; i++) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        t1--; t2--; t3--;
        adj[t1].push_back({t2, t3});
        adj[t2].push_back({t1, t3});
    }
    
    vector<vector<int>> g(n);
    for(int i = 0; i < n; i++) {
        g[i].push_back(i + n);
    }

    vector<int> sz(n), f(n + n);
    for(int i = 0; i < n; i++) {
        f[i + n] = n;
    }

    ll ans = 0;
    function<void(int, int)> dfs1 = [&](int u, int p) {
        sz[u] = 1;
        for(auto [v, x] : adj[u]) {
            if(v == p) continue;

            g[x].push_back(v);
            dfs1(v, u);
            sz[u] += sz[v];
            g[x].pop_back();
            f[g[x].back()] -= sz[v];
        }
        f[u] += sz[u];
    };

    dfs1(0, -1);

    function<void(int, int)> dfs2 = [&](int u, int p) {
        for(auto [v, x] : adj[u]) {
            if(v == p) continue;
            ans += 1LL * f[v] * f[g[x].back()];
            g[x].push_back(v);
            dfs2(v, u);
            g[x].pop_back();
        }
    };
    
    dfs2(0, -1);
    cout << ans << '\n';



    return 0;
}