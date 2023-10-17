#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};
int cost[51][51];
int dist[51][51];
int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    
    int sx, sy, ex, ey;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 'S') {
                sx = i, sy = j;
            } else if(a[i][j] == 'F') {
                ex = i, ey = j;
            } else if(a[i][j] == 'g') {
                cost[i][j] = 1000;
            } else {
                bool check = false;
                for(int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(a[nx][ny] == 'g') check = true;
                }
                if(check) cost[i][j] = 1;
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) dist[i][j] = 1e9;
    }

    dist[sx][sy] = 0;
    for(int i = 0; i < 4; i++) {
        int nx = sx + dx[i];
        int ny = sy + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(a[nx][ny] == 'g') {
            dist[sx][sy] = 1;
        }
    }

    

    priority_queue<tuple<int, int, int>> pq;
    pq.push({dist[sx][sy], sx, sy});

    while(!pq.empty()) {
        auto [d, x, y] = pq.top();
        d = -d;
        if(d > dist[x][y]) break;
        pq.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dist[nx][ny] > dist[x][y] + cost[nx][ny]) {
                dist[nx][ny] = dist[x][y]+ cost[nx][ny];
                pq.push({-dist[nx][ny], nx, ny});
            }
        }
    }
    
    cout << dist[ex][ey] / 1000 << ' ' << dist[ex][ey] % 1000 << '\n';
    return 0;
}