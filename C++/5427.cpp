#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int dist1[1002][1002];
int dist2[1002][1002];
int n, m;

int main() {
    fastio;
    int tc;
    cin >> tc;
    while(tc--) {
        memset(dist1,-1,sizeof(dist1));
        memset(dist2,-1,sizeof(dist2));
        cin >> m >> n;
        vector<string> a(n);
        queue<pair<int,int>> fire;
        queue<pair<int,int>> human;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            for(int j = 0; j < m; j++) {
                if(a[i][j] == '*') {
                    dist1[i][j] = 0;
                    fire.push({i,j});
                } else if(a[i][j] == '@') {
                    dist2[i][j] = 0;
                    human.push({i,j});
                }
            }
        }
    
        while(!fire.empty()) {
            auto &[x, y] = fire.front();
            fire.pop();

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(a[nx][ny] == '#' || dist1[nx][ny] != -1) continue;
                dist1[nx][ny] = dist1[x][y] + 1;
                fire.push({nx,ny});
            }
        }
        
        bool ok = false;
        while(!human.empty()) {
            if(ok) break;
            auto &[x, y] = human.front();
            human.pop();
            
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    cout << dist2[x][y] + 1 << '\n';
                    ok = true;
                    break;
                }
                
                if(a[nx][ny] == '#' || dist2[nx][ny] != -1) continue;
                if(dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[x][y] + 1) continue;
                dist2[nx][ny] = dist2[x][y] + 1;
                human.push({nx,ny});
            }
        }
        if(!ok) cout << "IMPOSSIBLE" << '\n';
    }     
      
    return 0;
}