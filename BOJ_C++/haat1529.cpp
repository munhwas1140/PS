#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m, s, e;
bool dfs(int now, vector<vector<int>> &g, vector<bool> &visited) {
    for(int &next : g[now]) {
        if(visited[next] == false) {
            visited[next] = true;
            dfs(next, g, visited);
        }
    }
    return visited[now];
}
int main() {
    fastio;
    cin >> n >> m;
    vector<vector<int>> g(n + 1, vector<int>()), gr(n + 1,vector<int>());
    for(int i = 0; i < m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        gr[t2].push_back(t1);
    }
    cin >> s >> e;

    vector<int> cnt(n + 1);
    vector<bool> visited1(n + 1), visited2(n + 2);
    visited1[e] = visited1[s] = true;
    visited2[e] = true;
    dfs(s, g, visited1);
    dfs(e, gr, visited2);

    for(int i = 1; i <= n; i++) {
        cnt[i] += (visited1[i] && visited2[i]);
    }

    visited2.assign(n + 1, false);
    visited1.assign(n + 1, false);
    visited2[s] = visited2[e] = true;
    visited1[s] = true;
    dfs(e, g, visited2);
    dfs(s, gr, visited1);

    for(int i = 1; i <= n; i++) {
        cnt[i] += (visited1[i] && visited2[i]);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += (cnt[i] == 2);
    }
    cout << ans - 2 << '\n';
    return 0;
}