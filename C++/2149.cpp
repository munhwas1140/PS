#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int n, m, r, c, k;
bool mp[500][500];
int dist[500][500];

bool check(int x, int y) {
    if(x < 0 || y < 0 || x + r - 1 >= n || y + c - 1 >= m) return false;
    for(int i = 0; i < r; i++) {
        if(mp[x + i][y]) return false;
        if(mp[x + i][y + c - 1]) return false;
    }
    for(int i = 0; i < c; i++) {
        if(mp[x][y + i]) return false;
        if(mp[x + r - 1][y + i]) return false;
    }
    return true;
}

int main() {
    fastio;
    cin >> n >> m >> r >> c >> k;

    for(int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        mp[x][y] = true;
    }
    
    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    sx--; sy--; ex--; ey--;


    memset(dist,-1,sizeof(dist));
    queue<pii> q;
    q.push({sx, sy});
    dist[sx][sy] = 0;

    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        // cout << x << ' ' << y << '\n';
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(dist[nx][ny] == -1 && check(nx, ny)) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    cout << dist[ex][ey] << '\n';

    return 0;
}