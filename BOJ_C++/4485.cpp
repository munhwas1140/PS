#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int dist[125][125];
int a[125][125];
int main() {
    fastio;
    
    for(int tc = 1; ; tc++) {
        int n; cin >> n;
        if(n == 0) break;
    
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> a[i][j];
                dist[i][j] = 1e9;
            }
        }
    
        dist[0][0] = a[0][0];
        
        priority_queue<tuple<int, int, int>> pq;
        pq.push({-a[0][0], 0, 0});

        while(!pq.empty()) {
            auto [d, x, y] = pq.top();
            pq.pop();
            d = -d;
            if(d > dist[x][y]) continue;
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                
                if(dist[nx][ny] > d + a[nx][ny]) {
                    dist[nx][ny] = d + a[nx][ny];
                    pq.push({-dist[nx][ny], nx, ny});
                }
            }
        }
        cout << "Problem " << tc << ": " << dist[n-1][n-1] << '\n';
    }
    return 0;
}