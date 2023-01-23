#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
bool imp[101][101][101][101];
bool a[101][101];
bool visited[101][101];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int main() {
    fastio;
    int n, k, r;
    cin >> n >> k >> r;
    for(int i = 0; i < r; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        imp[x1][y1][x2][y2] = true;
        imp[x2][y2][x1][y1] = true;
    }

    vector<int> st;

    for(int i = 0; i < k; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        a[t1][t2] = true;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(a[i][j] && !visited[i][j]) {
                queue<pii> q;
                q.push({i, j});
                int cnt = 1;
                visited[i][j] = true;

                while(!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();

                    for(int i = 0; i < 4; i++) {
                        int nx = x + dx[i];
                        int ny = y + dy[i];
                        if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
                        if(imp[x][y][nx][ny] || visited[nx][ny]) continue;
                        visited[nx][ny] = true;
                        if(a[nx][ny]) cnt++;
                        q.push({nx, ny});
                    }
                }
                st.push_back(cnt);
            }
        }
    }

    int m = st.size();
    ll ans = 0;
    for(int i = 0; i < m; i++) {
        for(int j = i + 1; j < m; j++) {
            ans += (ll)(st[i] * st[j]);
        }
    }
    cout << ans << '\n';
    return 0;
}