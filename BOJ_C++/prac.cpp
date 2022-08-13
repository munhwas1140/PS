#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long>> g[100001];
bool visited[100001];
int dp[100001][30];
int depth[100001];
long long dist[100001][30];
int n;

void DFS(int now, int d) {
    visited[now] = true;
    depth[now] = d;
    for(pair<int, long long> next : g[now]) {
        if(!visited[next.first]) {
            dp[next.first][0] = now;
            dist[next.first][0] = next.second;
            DFS(next.first, d + 1);
        }
    }
}

void dpSet() {
    for(int j = 1; j < 30; j++) {
        for(int i = 1; i <= n; i++) {
            dp[i][j] = dp[dp[i][j-1]][j-1];
            dist[i][j] = dist[i][j-1] + dist[dp[i][j-1]][j-1];
        }
    }
}

pair<long long, long long> LCA(int u, int v) {
    if(depth[u] < depth[v]) swap(u, v);

    long long ans = 0LL;
    int diff = depth[u] - depth[v];
    for(int i = 0; i < 30; i++) {
        if(diff & 1) {
            ans += dist[u][i];
            u = dp[u][i];
        }
    }
    if(u == v) return make_pair(ans, ans);

    for(int i = 29; i >= 0; i--) {
        if(dp[u][i] != dp[v][i]) {
            ans += dist[u][i] + dist[v][i];
            u = dp[u][i];
            v = dp[v][i];
        }
    }

    return make_pair(ans + dist[u][0] + dist[v][0], dist[u][29] + dist[v][29]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int t1, t2;
        long long t3;
        cin >> t1 >> t2 >> t3;
        g[t1].push_back({t2,t3});
        g[t2].push_back({t1,t3});
    }
    
    DFS(1, 0);
    dpSet();

    int q;
    cin >> q;
    while(q--) {
        int t1, t2;
        cin >> t1 >> t2;   
        pair<long long, long long> ans = LCA(t1, t2);    
        cout << ans.first << " " << ans.second << '\n';
    }

    return 0;
}