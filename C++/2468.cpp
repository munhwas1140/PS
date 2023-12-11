#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int a[100][100];
bool visited[100][100];
int n;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};


int main() {
    fastio;
    cin >> n;
    int minv = 1e9, maxv = -1e9;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            minv = min(minv, a[i][j]);
            maxv = max(maxv, a[i][j]);
        }
    }      

    int ans = 1; 
    for(int hei = minv; hei < maxv; hei++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(a[i][j] == hei) a[i][j] = -1;
            }
        }
        int cnt = 0;
        memset(visited,false,sizeof(visited));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(a[i][j] != -1 && !visited[i][j]) {
                    cnt++;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    visited[i][j] = true;
                    while(!q.empty()) {
                        auto &[x, y] = q.front();
                        q.pop();
                        for(int k = 0; k < 4; k++) {
                            int nx = x + dx[k];
                            int ny = y + dy[k];
                            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                            if(a[nx][ny] != -1 && !visited[nx][ny]) {
                                visited[nx][ny] = true;
                                q.push({nx,ny});
                            }
                        }
                    }
                }
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
    return 0;
}