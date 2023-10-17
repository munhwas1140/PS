#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
vector<int> g[1000];
int p[1000];
int l[1000], r[1000];
bool visited[1000];
bool dfs(int now) {
    visited[now] = true;
    for(int &next : g[now]) {
        if(r[next] == -1 || !visited[r[next]] && dfs(r[next])) {
            l[now] = next;
            r[next] = now;
            return true;
        }
    }
    return false;
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        for(int i = 0 ; i < 1000; i++) {
            g[i].clear();
        }
        cin >> n >> m;
        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
        }
        memset(l,-1,sizeof(l));
        memset(r,-1,sizeof(r));
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(l[i] == -1) {
                memset(visited,false,sizeof(visited));
                if(dfs(i)) ans++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}