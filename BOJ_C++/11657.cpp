#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
vector<pii> g[501];
ll dist[501];
int n, m;
int main() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        g[t1].push_back({t2, t3});
    } 
    for(int i = 1; i <= n; i++) {
        dist[i] = 1e12;
    }

    dist[1] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= n; j++) {
            if(dist[j] == 1e12) continue;
            for(auto &p : g[j]) {
                if(dist[p.first] > dist[j] + p.second) {
                    if(i == n - 1) return !(cout << -1 << '\n');
                    dist[p.first] = dist[j] + p.second;
                }
            }
        }
    }

    for(int i = 2; i <= n; i++) {
        cout << (dist[i] != 1e12 ? dist[i] : -1) << '\n';
    }
      
    return 0;
}