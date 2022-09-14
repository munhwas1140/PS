#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m, k;
vector<pair<int, ll>> g[10001];
ll dist[10001][21];
int main() {
    fastio;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            dist[i][j] = 1e14;
        }
    }
    for(int i = 0; i < m; i++) {
        int t1, t2;
        ll t3;
        cin >> t1 >> t2 >> t3;
        g[t1].push_back({t2, t3});
        g[t2].push_back({t1, t3});
    }

    priority_queue<tuple<ll, int, int>> pq;
    dist[1][0] = 0;
    pq.push({0, 0, 1});
    while(!pq.empty()) {
        auto [d, cnt, now] = pq.top();
        pq.pop();
        d = -d;
        if(d > dist[now][cnt]) continue;
        for(auto &next : g[now]) {
            if(dist[next.first][cnt] > d + next.second) {
                dist[next.first][cnt] = d + next.second;
                pq.push({-dist[next.first][cnt], cnt, next.first});
            }
            if(cnt < k && dist[next.first][cnt + 1] > d) {
                dist[next.first][cnt + 1] = d;
                pq.push({-dist[next.first][cnt + 1], cnt + 1, next.first});
            }
        }
    }
      
    ll ans = 1e14;
    for(int i = 0; i <= k; i++) {
        if(dist[n][i] == 1e14) continue;
        ans = min(ans, dist[n][i]);
    }
    cout << ans << '\n';
    return 0;
}