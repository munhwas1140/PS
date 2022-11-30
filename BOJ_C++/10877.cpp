#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int dist[500][500];
vector<pii> point;
char tran(int from, int to) {
    if(from == 0) {
        if(to == 1) return 'q';
        else return 'd';
    } else if(from == 1) {
        if(to == 0) return 'b';
        return 'd';
    } else if(from == 2) {
        if(to == 1) return 'p';
        return 'b';
    } else {
        if(to == 0) return 'p';
        return 'q';
    }
}
pii qnd(int now) {
    if(now == 0 || now == 2) {
        return {1, 3};
    } else return {0, 2};
}
bool go(int x, int y, int dir, vector<string> &a, vector<vector<bool>> &visited, vector<vector<bool>> &tar) {
    visited[x][y] = true;
    if(x == point[1].first && y == point[1].second) {
        dist[x][y] = (dir + 2) % 4;
        if(visited == tar) return true;
        dist[x][y] = -1;
        visited[x][y] = false;
        return false;
    }

    if(a[x][y] == 'O') {
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && a[nx][ny] != '*') {
                dist[x][y] = i;
                if(go(nx,ny,i,a,visited,tar)) {
                    return true;
                }
            }
        }
    } else if(a[x][y] == 'l') {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        dist[x][y] = dir;
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && a[nx][ny] != '*') {
            if(go(nx, ny, dir, a,visited,tar)) return true;
        }
    } else if(a[x][y] == 'q') {
        auto [nd1, nd2] = qnd(dir);

        int nx = x + dx[nd1];
        int ny = y + dy[nd1];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && a[nx][ny] != '*') {
            dist[x][y] = nd1;
            if(go(nx, ny, nd1, a, visited, tar)) return true;
        }

        nx = x + dx[nd2];
        ny = y + dy[nd2];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && a[nx][ny] != '*') {
            dist[x][y] = nd2;
            if(go(nx,ny,nd2,a,visited,tar)) return true;
        }
    }

    visited[x][y] = false;
    return false;
} 
void solve() {
    cin >> n >> m;

    point.clear();
    vector<string> a(n);
    vector<vector<bool>> tar(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = 0; j < m; j++) {
            if(a[i][j] != '*') {
                tar[i][j] = true;
            }
            if(a[i][j] == 'O') {
                if(point.size() == 0) {
                    point.push_back({i, j});
                } else {
                    point.push_back({i, j});
                }
            }
        }
    }


    memset(dist,-1,sizeof(dist));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    bool ok = go(point[0].first, point[0].second, -1, a, visited, tar);
    
    if(!ok) cout << "NO" << '\n';
    else {
        cout << "YES" << '\n';
        vector<string> ans(n, string(m, ' '));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(a[i][j] == 'O') {
                    if(dist[i][j] == 0) ans[i][j] = '>';
                    else if(dist[i][j] == 1) ans[i][j] = 'v';
                    else if(dist[i][j] == 2) ans[i][j] = '<';
                    else ans[i][j] = '^';
                } else if(a[i][j] == 'q') {
                    int from;
                    for(int k = 0; k < 4; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(dist[nx][ny] == (k + 2) % 4) {
                            from = (k + 2) % 4;
                            break;
                        }
                    }
                    ans[i][j] = tran(from, dist[i][j]);

                } else if(a[i][j] == 'l') {
                    if(dist[i][j] == 0 || dist[i][j] == 2) {
                        ans[i][j] = '-';
                    } else ans[i][j] = '|';
                } else if(a[i][j] == '*') {
                    ans[i][j] = '*';
                }

            }
        }

        for(int i = 0; i < n; i++) {
            cout << ans[i] << '\n';
        }
    }
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}