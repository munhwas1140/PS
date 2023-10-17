#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int n, m;
int dist1[51][51];
int dist2[51][51];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int main() {
    fastio;
    memset(dist1,-1,sizeof(dist1));
    memset(dist2,-1,sizeof(dist2));
    cin >> n >> m;
    vector<string> a(n);
    queue<pair<int,int>> water;
    queue<pair<int,int>> gosum;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 'S') {
                gosum.push({i,j});
                dist2[i][j] = 0;
            } else if(a[i][j] == '*') {
                water.push({i,j});
                dist1[i][j] = 0;
            }
        }
    } 

    while(!water.empty()) {
        auto &[x, y] = water.front();
        water.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(a[nx][ny] == 'X' || a[nx][ny] == 'D' || dist1[nx][ny] != -1) continue;
            dist1[nx][ny] = dist1[x][y] + 1;
            water.push({nx,ny});
        }    
    }

    int ans = -1;; 
    while(!gosum.empty()) {
        auto &[x, y] = gosum.front();
        gosum.pop();
        if(a[x][y] == 'D') {
            ans = dist2[x][y];
            break;
        }
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(a[nx][ny] == 'X' || dist2[nx][ny] != -1) continue;
            if(dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[x][y] + 1) continue;
            dist2[nx][ny] = dist2[x][y] + 1;
            gosum.push({nx,ny}); 
        }
    }
    
    if(ans == -1) cout << "KAKTUS" << '\n';
    else cout << ans << '\n';
      
    return 0;
}