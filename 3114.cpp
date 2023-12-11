#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n, m;
    cin >> n >> m;

    vector<vector<int>> pa(m + 1, vector<int>(n + 1));
    vector<vector<int>> pb(n + 1, vector<int>(m + 1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            char c; int tmp;
            cin >> c >> tmp;
            pb[i][j] = pb[i][j - 1] + (c == 'A' ? 0 : tmp);
            pa[j][i] = pa[j][i - 1] + (c == 'A' ? tmp : 0);
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    
    function<int(int, int)> go = [&] (int x, int y) {
        if(x == n && y == m) return 0;
        int &ret = dp[x][y];
        if(ret != -1) return ret;
        ret = 0;
        if(x + 1 <= n && y + 1 <= m) {
            ret = go(x + 1, y + 1) + pa[y][n] - pa[y][x] + pb[x][m] - pb[x][y];
        }
        if(x + 1 <= n) {
            ret = max(ret, go(x + 1, y) + pb[x][m] - pb[x][y]);
        }
        if(y + 1 <= m) {
            ret = max(ret, go(x, y + 1) + pa[y][n] - pa[y][x]);
        }
        // cout << x << ' ' << y << ' ' << ret << '\n';
        return ret;
    };

    cout << go(1, 1) << '\n';

    return 0;
}