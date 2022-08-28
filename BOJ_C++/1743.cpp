#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int a[101][101];
int n, m, k;
int DFS(int x, int y) {
    int ret = 1;
    a[x][y] = 0;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
        if(a[nx][ny]) ret += DFS(nx,ny);
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        a[t1][t2] = 1;
    }
    int ans = 0; 
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i][j]) ans = max(ans, DFS(i, j));
        }
    }
    cout << ans << '\n';
    return 0;
}