#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
int n, m;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int dist[1002][1002];
void BFS(vector<string> &a, vector<pair<int,int>> &fires, int sx, int sy) {
    memset(dist,-1,sizeof(dist));
    dist[sx][sy] = 0;
    queue<tuple<int,int,int>> q;
    for(auto &fire : fires) q.push(make_tuple(fire.first, fire.second, 1));
    q.push(make_tuple(sx, sy, 0));
    
    while(!q.empty()) {
        auto &[x, y, c] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                if(c == 0) {
                    cout << dist[x][y] + 1 << '\n';
                    return ;
                }
                continue;
            }
            if(c == 0) {
                if(dist[nx][ny] == -1 && a[nx][ny] != '*' && a[nx][ny] != '#') {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push(make_tuple(nx,ny,c));
                }
            } else if(c == 1) {
                if(a[nx][ny] != '#' && a[nx][ny] != '*') {
                    a[nx][ny] = '*';
                    q.push(make_tuple(nx,ny,c));
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}
int main() {
    fastio;
    int tc;
    cin >> tc;
    while(tc--) {
        cin >> m >> n;
        vector<string> a(n);
        vector<pair<int,int>> fires;
        int sx, sy;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            for(int j = 0; j < m; j++) {
                if(a[i][j] == '@') {
                    sx = i; sy = j;
                } else if(a[i][j] == '*') {
                    fires.push_back({i, j});
                }
            }
        }        
        BFS(a, fires, sx, sy);
    }     
      
    return 0;
}