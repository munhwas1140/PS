#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int n, m, k;
int a[100][100];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int DFS(int x, int y) {
    int ret = 1;
    a[x][y] = 1;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(!a[nx][ny]) ret += DFS(nx,ny);
    }
    return ret;
}
int main() {
    fastio;
    cin >> m >> n >> k;
    while(k--) {
        int t1, t2, t3, t4;
        cin >> t1 >> t2 >> t3 >> t4;
        for(int i = t1; i < t3; i++) {
            for(int j = t2; j < t4; j++) {
                a[i][j] = 1;
            }
        }
    } 

    vector<int> ans;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!a[i][j]) ans.push_back(DFS(i,j));
        }
    }
    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for(int &x : ans) cout << x << '\n';
    
    return 0;
}