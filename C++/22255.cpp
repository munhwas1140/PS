#include <bits/stdc++.h>

#include <queue>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
vector<int> dx[3] = {{1, -1, 0, 0}, {1, -1}, {0, 0}};
vector<int> dy[3] = {{0, 0, 1, -1}, {0, 0}, {1, -1}};

int n, m;
int sx, sy, ex, ey;

int a[100][100];
int dist[100][100][6];

int main() {
    fastio;

    cin >> n >> m;
    cin >> sx >> sy >> ex >> ey;

    sx--;
    sy--;
    ex--;
    ey--;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];

            for (int k = 0; k < 6; k++) {
                dist[i][j][k] = 1e9;
            }
        }
    }

    priority_queue<tuple<int, int, int, int>> pq;

    dist[sx][sy][1] = 0;
    pq.emplace(0, 1, sx, sy);

    while (!pq.empty()) {
        auto [d, cnt, x, y] = pq.top();
        pq.pop();

        d *= -1;

        if (cnt % 3 == 0) {
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[cnt % 3][k];
                int ny = y + dy[cnt % 3][k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (a[nx][ny] == -1) continue;
                if (dist[nx][ny][cnt % 6] > d + a[nx][ny]) {
                    dist[nx][ny][cnt % 6] = d + a[nx][ny];
                    pq.emplace(-dist[nx][ny][cnt % 6], cnt + 1, nx, ny);
                }
            }
        } else {
            for (int k = 0; k < 2; k++) {
                int nx = x + dx[cnt % 3][k];
                int ny = y + dy[cnt % 3][k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (a[nx][ny] == -1) continue;
                if (dist[nx][ny][cnt % 6] > d + a[nx][ny]) {
                    dist[nx][ny][cnt % 6] = d + a[nx][ny];
                    pq.emplace(-dist[nx][ny][cnt % 6], cnt + 1, nx, ny);
                }
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << min({dist[i][j][0], dist[i][j][1], dist[i][j][2]}) << '
    //         ';
    //     }
    //     cout << '\n';
    // }

    int ans = 1e9;
    for (int i = 0; i < 6; i++) {
        ans = min(ans, dist[ex][ey][i]);
    }

    if (ans == 1e9) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }

    return 0;
}