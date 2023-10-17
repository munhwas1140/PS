#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;

int n, m;
bool dist[401][401];
int main() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        dist[t1][t2] = true;
    }
    
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(dist[i][k] && dist[k][j]) dist[i][j] = true;
            }
        }
    }
    int q;
    cin >> q;
    while(q--) {
        int t1, t2;
        cin >> t1 >> t2;
        if(dist[t1][t2] == dist[t2][t1]) {
            cout << 0 << '\n';
        } else if(dist[t1][t2]) {
            cout << -1 << '\n';
        } else if(dist[t2][t1]) {
            cout << 1 << '\n';
        }
    }
      
    return 0;
}