#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
int n, m;
int Scnt;
vector<int> g[500001];
vector<int> gp[500001];
vector<int> gs[500001];
int a[500001];
int SCC[500001];
int Smoney[500001];
bool visited[500001];
int indeg[500001];
int dist[500001];
vector<int> order;
vector<int> dest;
int s;
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
vector<pair<int,int>> edge;
int main() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        gp[t2].push_back(t1);
        edge.push_back({t1, t2});
    }
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> s;
    int tmp;
    cin >> tmp; 
    dest.resize(tmp);
    for(int &x : dest) cin >> x;

    for(int i = 1; i <= n; i++) {
        if(!visited[i]) dfs(i);
    }

    memset(visited,false,sizeof(visited));
    reverse(order.begin(), order.end());

    for(int &i : order) {
        if(!SCC[i]) dfs_rev(i, ++Scnt);
    }


    for(int i = 1; i <= n; i++) {
        for(int &next : g[i]) {
            if(SCC[next] != SCC[i]) {
                gs[SCC[i]].push_back(SCC[next]);
                indeg[SCC[next]]++;
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        Smoney[SCC[i]] += a[i];
    }
    dist[SCC[s]] = Smoney[SCC[s]];
    queue<int> q;
    q.push(SCC[s]);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(int &next : gs[now]) {
            if(dist[next] < dist[now] + Smoney[next]) {
                dist[next] = dist[now] + Smoney[next];
                q.push(next);
            }
        }
    }
    
    int ans = 0;
    for(int &x : dest) {
        ans = max(ans, dist[SCC[x]]);
    }
    cout << ans << '\n';

    return 0;
}