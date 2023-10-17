#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int n, m, sx, sy;
vector<string> a;
int dist[50][50][1<<6];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int main() {
    fastio;
    cin >> n >> m;
    a.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = 0; j < m; j++) {
            if(a[i][j] == '0') {
                sx = i; sy = j;
            }
        }
    }
    memset(dist,-1,sizeof(dist));

    queue<tuple<int,int,int>> q;
    q.push({sx,sy,0});
    
    dist[sx][sy][0] = 0;
    int ans = -1;   
    while(!q.empty()) {
        auto [x, y, state] = q.front();
        q.pop();
        if(a[x][y] == '1') {
            ans = dist[x][y][state];
            break;
        }

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(a[nx][ny] == '#') continue;
            if(a[nx][ny] >= 'a' && a[nx][ny] <= 'f') {
                int k = a[nx][ny] - 'a';
                if(dist[nx][ny][state | (1 << k)] == -1) {
                    dist[nx][ny][state | (1 << k)] = dist[x][y][state] + 1;
                    q.push({nx,ny,state|(1<<k)});
                }
            } else if(a[nx][ny] >= 'A' && a[nx][ny] <= 'F') {
                int k = a[nx][ny] - 'A';
                if(state & (1 << k) && dist[nx][ny][state] == -1) {
                    dist[nx][ny][state] = dist[x][y][state] + 1;
                    q.push({nx,ny,state});
                }
            } else {
                if(dist[nx][ny][state] == -1) {
                    dist[nx][ny][state] = dist[x][y][state] + 1;
                    q.push({nx,ny,state});
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}