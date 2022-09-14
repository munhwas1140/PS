#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m, D, E;
ll h[100001];
vector<pair<int, ll>> g[100001];
ll dist[2][100001];
void di(int s, int idx) {
    dist[idx][s] = 0;
    priority_queue<pair<ll, int>> pq;
    pq.push({0, s});
    while(!pq.empty()) {
        auto [d, now] = pq.top();
        pq.pop();

        d = -d;
        if(dist[idx][now] < d) continue;
        for(auto &next : g[now]) {
            if(dist[idx][next.first] > d + next.second && h[next.first] > h[now]) {
                dist[idx][next.first] = d + next.second;
                pq.push({-dist[idx][next.first], next.first});
            }
        }
    }
}
int main() {
    fastio;
    cin >> n >> m >> D >> E;
    for(int i = 1; i <= n; i++) cin >> h[i];
    for(int i = 0; i < m; i++) {
        int t1, t2;
        ll t3;
        cin >> t1 >> t2 >> t3;
        g[t1].push_back({t2, t3});
        g[t2].push_back({t1, t3});
    }
    
    for(int i = 1; i <= n; i++) {
        dist[0][i] = dist[1][i] = 1e14;
    }
    
    di(1,0); di(n,1);
    ll ans = -1e14; 
    for(int i = 2; i < n; i++) {
        if(dist[0][i] == 1e14 || dist[1][i] == 1e14) continue;
        ll tmp = (dist[0][i] + dist[1][i]) * D;
        ans = max(ans, h[i] * E - tmp);
    }
    if(ans == -1e14) cout << "Impossible" << '\n';
    else cout << ans << '\n';
    return 0;
}