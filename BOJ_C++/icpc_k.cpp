#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int n, t, m, s, e;
ll dist[1000000];
int main() {
    fastio;
    cin >> n >> t >> m >> s >> e;
    for(int i = 0; i < n; i++) {
        dist[i] = 1e18;
    }
    dist[s] = 0;
    for(int i = 1; i <= t; i++) {
        queue<tuple<int,int,ll>> q;
        for(int j = 0; j < m; j++) {
            int t1, t2;
            ll t3;
            cin >> t1 >> t2 >> t3;
            if(dist[t1] != 1e18) {
                q.push({t1, t2, t3});
            }
            if(dist[t2] != 1e18) {
                q.push({t2, t1, t3});
            }
        }

        while(!q.empty()) {
            auto [x, y, cost] = q.front();
            q.pop();
            if(dist[y] > dist[x] + cost) {
                dist[y] = dist[x] + cost;
            }
        }
    }
    
    cout << (dist[e] == 1e18 ? -1 : dist[e]) << '\n';
    return 0;
}