#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dx[] = {-1,-1,-1,0,0,1,1};
int dy[] = {-1,0,1,-1,1,-1,1};
int n; 
int main() {
    fastio;
    cin >> n;
    vector<string> a(n);
    int sx, sy;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = 0; j < n; j++) {
            if(a[i][j] == 'F') {
                sx = i; sy = j;
            }
        }
    }

    int ans = 0;

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<pii> q;
    q.push({sx, sy});
    visited[sx][sy] = true;
    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for(int i = 0; i < 7; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(a[nx][ny] == '#') continue;
            if(!visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
                ans++;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}