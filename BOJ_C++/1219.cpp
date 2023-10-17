#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;

vector<pil> g[50];
vector<tuple<int, int, ll>> tp;
vector<int> pos;
ll dist[50];
ll a[50];
bool visited[50];
int n, s, e, m;

void dfs(int now) {
    visited[now] = true;
    for(auto &p : g[now]) {
        if(!visited[p.first]) dfs(p.first);
    }
}

int main() {
    fastio;
    cin >> n >> s >> e >> m;
    for(int i = 0; i < m; i++) {
        int t1, t2; ll t3;
        cin >> t1 >> t2 >> t3;
        g[t1].push_back({t2, t3});
        tp.push_back({t1, t2, t3});
    } 
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        dist[i] = -1e14;
    }

    dist[s] = a[s];
    
    for(int i = 0; i < n - 1; i++) {
        for(auto &[now, next, cost] : tp) {
            if(dist[now] != -1e14 && dist[next] < dist[now] - cost + a[next]) {
                dist[next] = dist[now] - cost + a[next];
            }
        }
    }

    for(auto &[now, next, cost] : tp) {
        if(dist[now] != -1e14 && dist[next] < dist[now] - cost + a[next]) {
            dist[next] = dist[now] - cost + a[next];
            pos.push_back(next);
        }
    }
    
    dfs(s);
    if(!visited[e]) return !(cout << "gg" << '\n');

    for(int &i : pos) {
        memset(visited, false, sizeof(visited));
        dfs(i);
        if(visited[e]) return !(cout << "Gee" << '\n');
    }

    cout << dist[e] << '\n';

    return 0;
}