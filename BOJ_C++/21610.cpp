#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
int a[50][50];
int dx[] = {0,0,-1,-1,-1,0,1,1,1};
int dy[] = {0,-1,-1,0,1,1,1,0,-1};
int diax[] = {-1,-1,1,1};
int diay[] = {-1,1,-1,1};

int cnt[50][50];
int main() {
    fastio;

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    vector<pii> pos;
    for(int i = 0; i < m; i++) {
        memset(cnt,-1,sizeof(cnt));
        int dir, s;
        cin >> dir >> s;
        if(i == 0) {
            pos.push_back({n - 1, 0});
            pos.push_back({n - 1, 1});
            pos.push_back({n - 2, 0});
            pos.push_back({n - 2, 1});
        }

        for(auto &[x, y] : pos) {
            x += dx[dir] * s + n * 100;
            y += dy[dir] * s + n * 100;
            x %= n; y %= n;
        }

        for(auto &[x, y] : pos) {
            a[x][y]++;
            cnt[x][y] = 0;
        }
        
        for(auto [x, y] : pos) {
            for(int k = 0; k < 4; k++) {
                int nx = x + diax[k];
                int ny = y + diay[k];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if(a[nx][ny]) cnt[x][y]++;
            }
        }

        pos = vector<pii>();
        for(int x = 0; x < n; x++) {
            for(int y = 0; y < n; y++) {
                if(cnt[x][y] == -1) {
                    if(a[x][y] >= 2) {
                        a[x][y] -= 2;
                        pos.push_back({x, y});
                    }
                } else {
                    a[x][y] += cnt[x][y];
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ans += a[i][j];
        }
    }

    cout << ans << '\n';

    return 0;
}