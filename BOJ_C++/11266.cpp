#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m, cnt;
int dfsn[10001], low[10001];
int par[10001];
vector<int> g[10001];
vector<int> ans;
void dfs(int now) {
    dfsn[now] = ++cnt;
    low[now] = cnt;
    int sub = 0;
    for(int next : g[now]) {
        if(next == par[now]) continue;

        if(!dfsn[next]) {
            par[next] = now;
            sub++;
            dfs(next);
            if(!par[now] && sub > 1) ans.push_back(now);
            else if(par[now] && low[next] >= dfsn[now]) ans.push_back(now);
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
    for(int x : ans) cout << x << ' ';
    cout << '\n';
    return 0;
}