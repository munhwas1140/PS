#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m, s, e;
bool visited[501];
vector<pii> g[501];
vector<int> p[501];
bool cant[501][501];
int dist[501];
void DFS(int now) {
    for(int &next : p[now]) {
        if(cant[next][now]) continue;
        cant[next][now] = 1;
        DFS(next);
    }
}
void init() {
    memset(visited,false,sizeof(visited));
    for(int i = 0; i < n; i++) {
        dist[i] = 1e9;
        g[i].clear();
        p[i].clear();
    }
}
int main() {
    fastio;
    while(true) {
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        cin >> s >> e;

        init();
       
        for(int i = 0; i < m; i++) {
            int t1, t2, t3;
            cin >> t1 >> t2 >> t3;
            g[t1].push_back({t2, t3});
        }
        
        dist[s] = 0;
        priority_queue<pii> pq;
        pq.push({0, s});
        while(!pq.empty()) {
            auto [d, now] = pq.top();
            pq.pop();
            d = -d;
            if(d > dist[now]) continue;
            for(auto &next : g[now]) {
                if(dist[next.first] > d + next.second) {
                    p[next.first].clear();
                    p[next.first].push_back(now);
                    dist[next.first] = d + next.second;
                    pq.push({-dist[next.first], next.first});
                } else if(dist[next.first] == d + next.second) {
                    p[next.first].push_back(now);
                }
            }
        }

        memset(visited,false,sizeof(visited));
        DFS(e);

        for(int i = 0; i < n; i++) dist[i] = 1e9;
        dist[s] = 0;
        pq.push({0, s});
        while(!pq.empty()) {
            auto [d, now] = pq.top();
            pq.pop();
            d = -d; 
            if(d > dist[now]) continue;
            for(auto &next : g[now]) {
                if(dist[next.first] > d + next.second && !cant[now][next.first]) {
                    dist[next.first] = d + next.second;
                    pq.push({-dist[next.first], next.first});
                }
            }
        }
        if(dist[e] == 1e9) cout << -1 << '\n';
        else cout << dist[e] << '\n'; 

    }
    return 0;
}