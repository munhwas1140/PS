#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
int n, m, s;
vector<pair<int,int>> g[20001];
int dist[20001];
int main() {
    fastio;
    cin >> n >> m >> s;
    for(int i = 1; i <= n; i++) dist[i] = 1e9;
    for(int i = 0; i < m; i++) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        g[t1].push_back({t2, t3});
    }
      
    
    dist[s] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push({0, s});
    
    while(!pq.empty()) {
        auto [d, now] = pq.top();
        pq.pop();
        
        d = -d;
        if(dist[now] < d) continue;
        for(auto &next : g[now]) {
            if(dist[next.first] > d + next.second) {
                dist[next.first] = d + next.second;
                pq.push({-dist[next.first], next.first});
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        if(dist[i] == 1e9) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }
    return 0;
}