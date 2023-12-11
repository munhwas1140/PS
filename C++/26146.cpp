#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
vector<int> g[200001];
vector<int> gp[200001];
bool visited[200001];
int SCC[200001];
int SCCsz;
vector<int> order;
void dfs(int now) {
    visited[now] = true;
    for(int next : g[now]) {
        if(!visited[next]) dfs(next);
    }
    order.push_back(now);
}
void dfs_rev(int now, int num) {
    visited[now] = true;
    SCC[now] = num;
    for(int next : gp[now]) {
        if(!visited[next]) dfs_rev(next, num);
    }
}
int dfs_scc(int now) {
    int ret = 1;
    for(int &next : SCCg[now]) {
        ret += dfs_scc(next);
    }
    return ret;
}
int main() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        gp[t2].push_back(t1);
    }

    for(int i = 1; i <= n; i++) {
        if(!visited[i]) dfs(i);
    }

    memset(visited,false,sizeof(visited));
    reverse(order.begin(), order.end());
    for(int i : order) {
        if(!SCC[i]) dfs_rev(i,++SCCsz);
    }

    cout << (SCCsz == 1 ? "Yes" : "No") << '\n';
    return 0;
}