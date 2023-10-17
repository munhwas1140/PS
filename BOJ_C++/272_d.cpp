#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(n, -1));
    a[0][0] = 0;
    vector<pii> dir;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            if(i * i + j * j == m) {
                dir.push_back({i, j});
                dir.push_back({-i, j});
                dir.push_back({i,-j});
                dir.push_back({-i, -j});
            }
        }
    }

    queue<pii> q;
    q.push({0, 0});

    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for(auto &p : dir) {
            int nx = x + p.first;
            int ny = y + p.second;
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(a[nx][ny] != -1) continue;
            a[nx][ny] = a[x][y] + 1;
            q.push({nx, ny});
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}