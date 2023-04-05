#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m, d;
int a[16][15];
int b[16][15];
int dist[16][15];
int dx[] = {0,-1,0};
int dy[] = {-1,0,1};
pii check(int s) {
    memset(dist,-1,sizeof(dist));
    dist[n][s] = 0;

    queue<pii> q;
    q.push({n, s});

    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if(dist[x][y] > d) continue;
        if(b[x][y] == 1) {
            return make_pair(x, y);
        }

        for(int k = 0; k < 3; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx < 0 || nx > n || ny < 0 || ny >= m) continue;
            if(dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return make_pair(-1, -1);
}
void down() {
    for(int i = n - 2; i >= 0; i--) {
        for(int j = 0; j < m; j++) {
            b[i + 1][j] = b[i][j];
        }
    }
    for(int i = 0; i < m; i++) {
        b[0][i] = 0;
    }

    return ;
}

int go(int x, int y, int z) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            b[i][j] = a[i][j];
        }
    }

    int ans = 0;

    
    for(int t = 0; t < n; t++) {
        vector<pii> v;
        v.push_back(check(x));
        v.push_back(check(y));
        v.push_back(check(z));

        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        for(auto [u, v] : v) {
            if(u != -1) {
                ans++;
                b[u][v] = 0;
            }
        }
        down();
    }

    return ans;
}

int main() {
    fastio;
    cin >> n >> m >> d;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    
    int ans = 0;
    for(int i = 0; i < m; i++) {
        for(int j = i + 1; j < m; j++) {
            for(int k = j + 1; k < m; k++) {
                ans = max(ans, go(i, j, k));
            }
        }
    }

    cout << ans << '\n';

    return 0;
}