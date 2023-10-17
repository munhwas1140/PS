#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int n, m, k;
string str;
int sz;
string a[100];
int dp[100][100][80];

int go(int x, int y, int idx) {
    if(idx == sz - 1) return 1;

    int &ret = dp[x][y][idx];
    if(ret != -1) return ret;
    ret = 0;

    for(int i = 0; i < 4; i++) {
        for(int d = 1; d <= k; d++) {
            int nx = x + dx[i] * d;
            int ny = y + dy[i] * d;
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(a[nx][ny] == str[idx + 1]) {
                ret += go(nx, ny, idx + 1);
            }
        }
    }
    return ret;
}
int main() {
    fastio;

    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> str;
    sz = str.size();

    int ans = 0;
    memset(dp,-1,sizeof(dp));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == str[0]) {
                ans += go(i, j, 0);
            }
        }
    }
    cout << ans << '\n';

    return 0;
}