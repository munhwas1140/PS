#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m, cnt;
int dfsn[100001], low[100001], par[100001];
vector<int> g[100001];
vector<pii> ans;
void dfs(int now) {
    dfsn[now] = ++cnt;
    low[now] = cnt;

    for(int next : g[now]) {
        if(par[now] == next) continue;

        if(!dfsn[next]) {
            par[next] = now;
            dfs(next);
            
            if(low[next] > dfsn[now]) {
                ans.push_back({min(now, next), max(now, next)});
            }

            low[now] = min(low[now], low[next]);

        } else {
            low[now] = min(low[now], dfsn[next]);
        }
    }
}
int main() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }

    for(int i = 1; i <= n; i++) {
        if(!dfsn[i]) dfs(i);
    }
    
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << (int)ans.size() << '\n';
    for(auto &[u, v] : ans) {
        cout << u << ' ' << v << '\n';
    }
    
    return 0;
}