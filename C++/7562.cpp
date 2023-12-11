#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int dx[] = {-2,-2,-1,1,2,2,1,-1};
int dy[] = {1,-1,-2,-2,-1,1,2,2};
int dist[500][500];
int main() {
    fastio;
    int tc;
    cin >> tc;
    while(tc--) {
        memset(dist,-1,sizeof(dist));
        int n;
        cin >> n;
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        queue<pair<int,int>> q;
        dist[sx][sy] = 0;
        q.push({sx,sy});
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if(x == ex && y == ey) break;
            
            for(int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if(dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        } 
        cout << dist[ex][ey] << '\n';
    }     
      
    return 0;
}