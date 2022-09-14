#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int n, m, k;
vector<tuple<int, int, int>> g[101];
int dist[101][10001];
void init() {
    for(int i = 0; i < 101; i++) {
        g[i].clear();
        for(int j = 0; j < 10001; j++) {
            dist[i][j] = 1e9;
        }
    }
}
int main() {
    fastio;
    int tc;
    cin >> tc;
    while(tc--) {
        init();
        cin >> n >> m >> k;
        for(int i = 0; i < k; i++) {
            int t1, t2, t3, t4;
            cin >> t1 >> t2 >> t3 >> t4;
            g[t1].push_back({t2, t3, t4});
        }

        dist[1][m] = 0;
        priority_queue<tuple<int, int, int>> pq;
        pq.push({0, m, 1});

        while(!pq.empty()) {
            auto [d, money, now] = pq.top();
            pq.pop();
            d = -d;
            if(d > dist[now][money]) continue;
            for(auto &[next, cost, time] : g[now]) {
                if(cost <= money && dist[next][money - cost] > d + time) {
                    dist[next][money - cost] = d + time;
                    pq.push({-dist[next][money - cost], money - cost, next});
                }
            }
        }
        
        int ans = 1e9;
        for(int i = 0; i <= m; i++) {
            ans = min(ans, dist[n][i]);
        }
        if(ans == 1e9) cout << "Poor KCM" << '\n';
        else cout << ans << '\n';
    }     
      
    return 0;
}