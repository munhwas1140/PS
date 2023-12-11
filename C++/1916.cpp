#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
int n, m, s, e;
vector<pair<int, ll>> g[1001];
ll dist[1001];
int main() {
    fastio;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        dist[i] = 1e12;
    }
    for(int i = 0; i < m; i++) {
        int t1, t2;
        ll cost;
        cin >> t1 >> t2 >> cost;
        g[t1].push_back({t2, cost});
    }
    cin >> s >> e;

    dist[s] = 0;
    priority_queue<pair<ll, int>> pq;
    pq.push({0, s});
    
    while(!pq.empty()) {
        auto [d, now] = pq.top();
        pq.pop();
        d = -d;
        if(d > dist[now]) continue;
        for(auto &next : g[now]) {
            if(dist[next.first] > d + next.second) {
                dist[next.first] = d + next.second;
                pq.push({-dist[next.first], next.first});
            }
        }
    }
    cout << dist[e] << '\n';
      
    return 0;
}