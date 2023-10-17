#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
int dist[51][51];
bool visited[51][51];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
string a[51];
void go(int x, int y) {
    int tmp = a[x][y] - '0';
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i] * tmp;
        int ny = y + dy[i] * tmp;
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(a[nx][ny] == 'H') continue;
        if(!visited[nx][ny]) {
            if(dist[nx][ny] == 0 || dist[nx][ny] < dist[x][y] + 1) {
                visited[nx][ny] = true;
                dist[nx][ny] = dist[x][y] + 1;
                go(nx, ny);
                visited[nx][ny] = false;
            }
        } else {
            cout << -1 << '\n';
            exit(0);
        }
    }
}
int main() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if(a[0][0] == 'H') return !(cout << 0 << '\n');
    dist[0][0] = 1;
    visited[0][0] = true;
    go(0, 0);
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            ans = max(ans, dist[i][j]);
        }
    }
    cout << ans << '\n';
    return 0;
}