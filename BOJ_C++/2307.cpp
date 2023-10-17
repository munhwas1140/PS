#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
vector<pii> g[1001];
int dist[1001], p[1001];
int main() {
    fastio;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int s, e, x;
        cin >> s >> e >> x;
        g[s].push_back({e, x});
        g[e].push_back({s, x});
    }


    memset(dist, -1, sizeof(dist));
    memset(p, -1, sizeof(p));
    dist[1] = 0;
    
    priority_queue<pii> pq;
    pq.push({0, 1});
    
    while(!pq.empty()) {
        auto [d, now] = pq.top();
        pq.pop();
        d = -d;
        if(dist[now] < d) continue;
        for(auto [next, cost] : g[now]) {
            if(dist[next] == -1 || dist[next] > dist[now] + cost) {
                p[next] = now;
                dist[next] = dist[now] + cost;
                pq.push({-dist[next], next});
            }
        }
    }

    int ret = dist[n];
    int ans = 0;
    int t1 = n;
    while(t1 != -1) {
        memset(dist,-1, sizeof(dist));
        int t2 = p[t1];
        dist[1] = 0;
        pq.push({0, 1});
        while(!pq.empty()) {
            auto [d, now] = pq.top();
            pq.pop();
            d = -d;
            if(dist[now] < d) continue;
            for(auto [next, cost] : g[now]) {
                if(now == t1 && next == t2 || now == t2 && next == t1) continue;
                if(dist[next] == -1 || dist[next] > dist[now] + cost) {
                    dist[next] = dist[now] + cost;
                    pq.push({-dist[next], next});
                }
            }
        }   

        if(dist[n] == -1) return !(cout << -1 << '\n');
        else {
            ans = max(ans, dist[n] - ret);
        }
        
        t1 = p[t1];
    }

    cout << ans << '\n';

    return 0;
}