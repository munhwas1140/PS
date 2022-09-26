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
int g[101][101];
int main() {
    fastio;
    cin >> n >> m;
    while(m--) {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1][t2] = g[t2][t1] = 1;
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            for(int k = j + 1; k <= n; k++) {
                if(g[i][j] && g[j][k] && g[k][i]) {
                    ans++;
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}