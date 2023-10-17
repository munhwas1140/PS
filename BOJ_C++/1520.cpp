#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(m, -1));
    

    function<int(int, int)> go = [&] (int x, int y) {
        if(x == n - 1 && y == m - 1) return 1;
        int &ret = dp[x][y];
        if(ret != -1) return ret;
        ret = 0;
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(a[nx][ny] < a[x][y]) {
                ret += go(nx, ny);
            }
        }
        return ret;
    };

    cout << go(0, 0) << '\n';

    return 0;
}