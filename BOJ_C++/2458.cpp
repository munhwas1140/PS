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
int dist[501][501];
int main() {
    fastio;
    cin >> n >> m;     
    
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dist[i][j] = (i == j ? 0 : 1e9);
        }
    }
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        dist[b][a] = 1;
    }
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    int check[501] = {0, };
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int tmp = 1;
            if(dist[i][j] == 1e9 || dist[i][j] == 0) tmp = 0;
            check[i] += tmp; 
            check[j] += tmp; 
        }
    }
    
    int ans = 0;

    for(int i = 1; i <= n; i++) {
        if(check[i] == n - 1) ans += 1;
    }
    cout << ans << '\n';
    return 0;
}