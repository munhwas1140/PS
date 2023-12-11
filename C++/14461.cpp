#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
ll dist[101][101][3];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int main() {
    fastio;
    int n, t;
    cin >> n >> t;
    vector<vector<int>> a(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            for(int k = 0; k < 3; k++) {
                dist[i][j][k] = 1e18;
            }
        }
    }


    dist[0][0][0] = 0;

    priority_queue<tuple<ll,int,int,int>> pq;
    pq.push({0LL,0,0,0});
    
    while(!pq.empty()) {
        auto [d, x, y, c] = pq.top();
        pq.pop();
        d = -d;
        if(dist[x][y][c] < d) continue;

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            ll nd = d + t + (c == 2 ? a[nx][ny] : 0);
            int nc = (c + 1) % 3;
            if(nd < dist[nx][ny][nc]) {
                dist[nx][ny][nc] = nd;
                pq.push({-nd, nx, ny, nc});
            }
        }
    }
    
    cout << min({dist[n-1][n-1][0], dist[n-1][n-1][1], dist[n-1][n-1][2]}) << '\n';

    return 0;
}