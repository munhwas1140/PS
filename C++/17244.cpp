#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int dist[50][50][1 << 5];
int main() {
    fastio;
    int n, m;
    cin >> m >> n;
    vector<string> a(n);
    vector<vector<int>> mp(n, vector<int>(m, -1));
    int cnt = 0;
    int sx, sy, ex, ey;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 'S') {
                sx = i;
                sy = j;
            } else if(a[i][j] == 'X') {
                mp[i][j] = cnt++;
            }
        }
    }

    memset(dist,-1,sizeof(dist));

    dist[sx][sy][0] = 0;
    queue<tuple<int,int,int>> q;
    q.push({sx, sy, 0});
    while(!q.empty()) {
        auto [x, y, state] = q.front();
        q.pop();
        if(a[x][y] == 'E' && state == (1 << cnt) - 1) {
            cout << dist[x][y][state] << '\n';
            return 0;
        }

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(a[nx][ny] == '#') continue;
            int ns = state;
            if(mp[nx][ny] != -1) {
                ns |= (1 << mp[nx][ny]);
            }
            
            if(dist[nx][ny][ns] == -1) {
                dist[nx][ny][ns] = dist[x][y][state] + 1;
                q.push({nx, ny, ns});
            }
        }
    }

    return 0;
}