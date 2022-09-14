#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int dist[100][100];
int n, m;

int main() {
    fastio;
    cin >> m >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            dist[i][j] = 1e9;
        }
    }
    vector<string> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    priority_queue<tuple<int, int, int>> pq;
    dist[0][0] = 0;
    pq.push({0, 0, 0});
    
    while(!pq.empty()) {
        auto [d, x, y] = pq.top();
        pq.pop();
        d = -d; 
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            int nd = d;
            if(a[nx][ny] == '1') nd = d + 1;
            if(dist[nx][ny] > nd) {
                dist[nx][ny] = nd;
                pq.push({-nd, nx, ny});
            }
        }
    }
    cout << dist[n-1][m-1] << '\n';

    return 0;
}