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
int dist[251][251];
int main() {
    memset(dist, -1, sizeof(dist));
    fastio;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        dist[t1][t2] = 0;
        if(t3) dist[t2][t1] = 0;
        else dist[t2][t1] = 1;
    }
    
    for(int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(dist[i][k] != -1 && dist[k][j] != -1) {
                    if(dist[i][j] == -1 || dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }

    int q;
    cin >> q;
    while(q--) {
        int t1, t2;
        cin >> t1 >> t2;
        cout << dist[t1][t2] << '\n';
    }
    return 0;
}