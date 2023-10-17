#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int g[201][201];
int ans[201][201];
int main() {
    fastio;
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            g[i][j] = 1e9;
            if(i == j) g[i][j] = 0;
        }
    }

    for(int i = 0; i < m; i++) {
        int s, e, x;
        cin >> s >> e >> x;
        g[s][e] = x;
        g[e][s] = x;
        ans[s][e] = e;
        ans[e][s] = s;
    }
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(g[i][j] > g[i][k] + g[k][j]) {
                    g[i][j] = g[i][k] + g[k][j];
                    ans[i][j] = ans[i][k];
                }
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) cout << "- ";
            else cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}