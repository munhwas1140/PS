#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
int n, m, x;
vector<pii> g[1001];
int dist[1001][1001];
int main() {
    fastio;
    cin >> n >> m >> x;
    for(int i = 0; i < m; i++) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        g[t1].push_back({t2, t3});
    }
      
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dist[i][j] = 1e9;
        }
    }
    
    for(int i = 1; i <= n; i++) {
        dist[i][i] = 0;
        priority_queue<pii> pq;
        pq.push({0, i});
    
        while(!pq.empty()) {
            auto [d, now] = pq.top();
            pq.pop();
            d = -d;
            if(d < dist[i][now]) continue;
            for(auto &next : g[now]) {
                if(dist[i][next.first] > d + next.second) {
                    dist[i][next.first] = d + next.second;
                    pq.push({-dist[i][next.first], next.first});
                }
            }
        }
    }
    
    int ans = -1e9;
    for(int i = 1; i <= n; i++) {
        if(i == x) continue;
        ans = max(ans, dist[i][x] + dist[x][i]);
    }
    cout << ans << '\n';
    return 0;
}