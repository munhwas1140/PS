#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;

int dist[101][101];
int main() {
    fastio;
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dist[i][j] = (i == j) ? 0 : 1e9;
        }
    }
    for(int i = 0; i < m; i++) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        dist[t1][t2] = min(dist[t1][t2], t3);
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); 
            }
        }
    }
      
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << (dist[i][j] == 1e9 ? 0 : dist[i][j]) << ' ';
        }
        cout << '\n';
    }
    return 0;
}