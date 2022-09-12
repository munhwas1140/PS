#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
int n, m, f, s, e;
ll dist[50000][2];
vector<pair<int,ll>> g[50000];
int main() {
    fastio;
    cin >> n >> m >> f >> s >> e; 
    for(int i = 0; i < n; i++) dist[i][0] = dist[i][1] = 1e12;
    for(int i = 0; i < m; i++) {
        int t1, t2;
        ll cost;
        cin >> t1 >> t2 >> cost;
        g[t1].push_back({t2, cost});
        g[t2].push_back({t1, cost});
    }
    for(int i = 0; i < f; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back({t2, -1});
    }
      
    priority_queue<tuple<ll, int, int>> pq;
    dist[s][0] = 0;
    pq.push({0, s, 0});

    while(!pq.empty()) {
        auto [d, now, cnt] = pq.top();
        pq.pop();
        d = -d;
        for(auto &next : g[now]) {
            ll cost = next.second;
            if(cost == -1) {
                if(cnt == 1) continue;
                cost = 0;
                cnt = 1;
            }
            if(dist[next.first][cnt] > d + cost) {
                dist[next.first][cnt] = d + cost;
                pq.push({-dist[next.first][cnt], next.first, cnt});
            }
        }
    }
    cout << min(dist[e][0], dist[e][1]) << '\n';
    return 0;
}