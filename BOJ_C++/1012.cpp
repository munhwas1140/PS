#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int a[50][50];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n, m, k;

void dfs(int x, int y) {
    a[x][y] = 0;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(a[nx][ny] == 1) dfs(nx, ny);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    while(tc--) {
        cin >> n >> m >> k;
        while(k--) {
            int t1, t2;
            cin >> t1 >> t2;
            a[t1][t2] = 1;
        } 
        
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(a[i][j]) { 
                    dfs(i,j);
                    cnt += 1;
                }
            }
        }
        cout << cnt << '\n';
    }    
    return 0;
}