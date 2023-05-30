#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n, m;
string a[500];
bool visited[500][500];
int sx, sy, ex, ey;
bool solve() {
    a[sx][sy] = '.';
    bool check = false;
    int cnt = 0;
    if(a[ex][ey] == 'X') {
        check = true;
    }
    for(int i = 0; i < 4; i++) {
        int nx = ex + dx[i];
        int ny = ey + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(a[nx][ny] != 'X') cnt++;
    }
    if(sx == ex && sy == ey) {
        return cnt >= 1;
    }
    a[ex][ey] = '.';
    queue<pii> q;
    q.push({sx, sy});
    visited[sx][sy] = true;

    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if(x == ex && y == ey) {
            if(check || cnt >= 2) return true;
            return false;
        }
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(a[nx][ny] != 'X' && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return false;
}
int main() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> sx >> sy >> ex >> ey;
    sx--; sy--; ex--; ey--;

    if(solve()) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    
    return 0;
}