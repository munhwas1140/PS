#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n, m;
int a[1000][1000];
bool visited[1000][1000];
int main() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 0 && !visited[i][j]) {
                ans++;

                queue<pii> q;
                q.push({i, j});
                int x, y;
                while(!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    for(int k = 0; k < 4; k++) {
                        int nx = (x + dx[k] + n) % n;
                        int ny = (y + dy[k] + m) % m;
                        if(a[nx][ny] == 0 && !visited[nx][ny]) {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}