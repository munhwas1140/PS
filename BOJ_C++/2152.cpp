#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;

int n, m, s, t;
vector<int> g[10001];
vector<int> gp[10001];
vector<int> gs[10001];
vector<int> order;
int dist[10001];
bool visited[10001];
int SCC[10001];
int SCC_sz[10001];
void dfs(int now) {
    visited[now] = true;
    for(int &next : g[now]) {
        if(!visited[next]) dfs(next);
    }
    order.push_back(now);
}
void dfs_rev(int now, int num) {
    visited[now] = true;
    SCC[now] = num;
    for(int &next : gp[now]) {
        if(!visited[next]) dfs_rev(next, num);
    }
}
int main() {
    fastio;
    cin >> n >> m >> s >> t;
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
    
    int cnt = 0;
    for(int &i : order) {
        if(!SCC[i]) dfs_rev(i, ++cnt);
    }

    for(int i = 1; i <= n; i++) {
        SCC_sz[SCC[i]]++;
    }

    for(int i = 1; i <= n; i++) {
        for(int &next : g[i]) {
            int t1 = SCC[i];
            int t2 = SCC[next];
            if(t1 != t2) {
                gs[t1].push_back(t2);
            }
        }
    }
    queue<int> q;
    q.push(SCC[s]);
    dist[SCC[s]] = SCC_sz[SCC[s]];
    
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(int &next : gs[now]) {
            if(dist[next] < dist[now] + SCC_sz[next]) {
                dist[next] = dist[now] + SCC_sz[next];
                q.push(next);
            }
        }
    }

    
    if(dist[SCC[t]] == 0) {
        cout << 0 << '\n';
    } else {
        cout << dist[SCC[t]] << '\n';
    }
    
    return 0;
}