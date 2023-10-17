#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int n, m;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int dist[1000][1000][2];
int main() {
    fastio;
    memset(dist,-1,sizeof(dist));
    cin >> n >> m;
    vector<string> a(n);
    for(string &s : a) cin >> s;
    
    dist[0][0][0] = 1;
    queue<tuple<int,int,int>> q;
    q.push({0,0,0});
    while(!q.empty()) {
        auto [x, y, c] = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            
            if(a[nx][ny] == '1') {
                if(c == 0 && dist[nx][ny][1] == -1) {
                    dist[nx][ny][1] = dist[x][y][c] + 1;
                    q.push({nx,ny,1});
                }
            } else if(a[nx][ny] == '0') {
                if(dist[nx][ny][c] == -1) {
                    dist[nx][ny][c] = dist[x][y][c] + 1;
                    q.push({nx,ny,c});
                }
            }
        }
    }

    if(dist[n-1][m-1][0] == -1) {
        cout << dist[n-1][m-1][1] << '\n';
    } else if(dist[n-1][m-1][1] == -1) {
        cout << dist[n-1][m-1][0] << '\n';
    } else cout << min(dist[n-1][m-1][0], dist[n-1][m-1][1]) << '\n';

      
    return 0;
}