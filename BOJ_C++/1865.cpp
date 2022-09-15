#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        int n, m, w;
        cin >> n >> m >> w;
        vector<int> dist(n + 1);
        vector<tuple<int,int,int>> g;

        for(int i = 0; i < m; i++) {
            int t1, t2, t3;
            cin >> t1 >> t2 >> t3;
            g.push_back(make_tuple(t1, t2, t3));
            g.push_back(make_tuple(t2, t1, t3));
        } 

        for(int i = 0; i < w; i++) {
            int t1, t2, t3;
            cin >> t1 >> t2 >> t3;
            g.push_back(make_tuple(t1, t2, -t3));
        }

        bool ok = true;
        for(int i = 0; i < n; i++) {
            for(auto &[now, next, cost] : g) {
                if(dist[next] > dist[now] + cost) {
                    if(i == n - 1) ok = false;
                    dist[next] = dist[now] + cost;
                }
            }
        }
        
        if(ok) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }     
      
    return 0;
}