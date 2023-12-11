#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n, m;
int a[1000][1000];
int dist[1000][1000];
int main() {
    fastio;     
    cin >> m >> n;

    memset(dist,-1,sizeof(dist));
    queue<pair<int,int>> q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            if(a[i][j] == 1) {
                q.push({i, j});
                dist[i][j] = 0;
            } 
        }
    }

    int ans = -1; 
    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        ans = max(ans, dist[x][y]); 
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(a[nx][ny] == 0) {
                a[nx][ny] = 1;
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx,ny});
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 0) return !(cout << -1 << '\n');
        }
    }

    cout << ans << '\n';
    return 0;
}