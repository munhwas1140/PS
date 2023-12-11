#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
int n, m;
vector<string> a;
int dist[1000][1000];
int mx, my, md, sx, sy;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int main() {
    fastio;
    int tc;
    cin >> tc;
    while(tc--) {
        cin >> m >> n;
        a.clear();
        a.resize(n);
        sx = sy = md = sx = sy = -1;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            for(int j = 0; j < m && sx == -1; j++) {
                if(a[i][j] == '.') {
                    sx = i; sy = j;
                }
            }
        }
        
        memset(dist,-1,sizeof(dist));
        
        queue<pair<int,int>> q;
        q.push({sx, sy});
        dist[sx][sy] = 0;
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if(dist[x][y] > md) {
                md = dist[x][y];
                mx = x; my = y;
            } 
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(a[nx][ny] == '.' && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx,ny});
                }        
            }
        }
        memset(dist,-1,sizeof(dist));
        md = -1;
        dist[mx][my] = 0;
        q.push({mx,my});
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if(dist[x][y] > md) {
                md = dist[x][y];
            } 
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(a[nx][ny] == '.' && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }
        cout << "Maximum rope length is " << md << '.' << '\n';
    }         
      
    return 0;
}