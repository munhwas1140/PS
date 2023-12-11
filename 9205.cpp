#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;

int cost[102][102];
vector<pair<int,int>> a;
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        a.clear(); 
        for(int i = 0; i < 102; i++) {
            for(int j = 0; j < 102; j++) {
                cost[i][j] = (i == j ? 0 : 1e9);
            }
        }
        int n; cin >> n;
        for(int i = 0; i < n + 2; i++) {
            int x, y;
            cin >> x >> y;
            a.push_back({x, y});
        }

        for(int i = 0; i < n + 2; i++) {
            for(int j = 0; j < n + 2; j++) {
                int dist = abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second);
                if(dist <= 1000) cost[i][j] = dist;
            }
        } 

        for(int k = 0; k < n + 2; k++) {
            for(int i = 0; i < n + 2; i++) {
                for(int j = 0; j < n + 2; j++) {
                    cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
                }
            }
        }
        
        if(cost[0][n+1] != 1e9) cout << "happy" << '\n';
        else cout << "sad" << '\n';
        
    }     
      
    return 0;
}