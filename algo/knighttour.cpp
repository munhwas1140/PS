#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
int n, m, sx, sy;
int dx[] = {-1,-2,-2,-1,1,2,2,1};
int dy[] = {-2,-1,1,2,2,1,-1,-2};
int dist[9][9];

void init() {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) dist[i][j] = 0;
    }
}

bool go(int x, int y, int idx) {
    dist[x][y] = idx;
    if(idx == n * m) return true;
    
    for(int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
        if(dist[nx][ny] == 0 && go(nx, ny, idx + 1)) return true;
    }
    dist[x][y] = 0;
    return false;
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        init();
        cin >> n >> m >> sx >> sy;
        if(go(sx, sy, 1)) {
            cout << 1 << '\n';
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= m; j++) {
                    cout << dist[i][j] << ' ';
                }
                cout << '\n';
            }
        } else {
            cout << 0 << '\n';
        }
    }
    return 0;
}