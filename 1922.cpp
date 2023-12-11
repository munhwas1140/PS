// prim's algorithm

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
int g[1001][1001];
int dist[1001];
bool check[1001];
int main() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        g[t1][t2] = t3;
        g[t2][t1] = t3;
    }

    int ans = 0;

    for(int i = 1; i <= n; i++) {
        dist[i] = 1e9;
    }

    dist[1] = 0;
    for(int i = 1; i <= n; i++) {
        int now = -1;
        int minval = 1e9;
        for(int j = 1; j <= n; j++) {
            if(!check[j] && minval > dist[j]) {
                minval = dist[j];
                now = j;
            }
        }
        
        ans += minval;
        check[now] = true;
        for(int j = 1; j <= n; j++) {
            if(g[now][j]) {
                dist[j] = min(dist[j], g[now][j]);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}