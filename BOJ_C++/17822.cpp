#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};
int n, m, t;
bool valid[51][51];
void turn(vector<vector<int>> &a, int i, int d, int k) {
    if(d == 0) {
        k = m - k;
    }
    reverse(a[i].begin(), a[i].begin() + k);
    reverse(a[i].begin() + k, a[i].end());
    reverse(a[i].begin(), a[i].end());
}
void check(vector<vector<int>> &a) {
    vector<vector<bool>> visited(n, vector<bool>(m));
    int sum = 0, cnt = 0;
    vector<pii> remove;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(valid[i][j] == false) continue;
            
            cnt++;
            sum += a[i][j];

            if(visited[i][j]) continue;
            queue<pii> q;
            visited[i][j] = true;
            q.push({i, j});
            bool f = false;
            while(!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                
                for(int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = (y + dy[dir]) % m;
                    if(nx < 0 || nx >= n) continue;
                    if(a[nx][ny] == a[i][j] && !visited[nx][ny]) {
                        f = true;
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                        remove.push_back({nx, ny});
                    }
                }
            }
            if(f) remove.push_back({i, j});
        }
    }

    if(remove.size()) {
        for(auto &[x, y] : remove) {
            valid[x][y] = false;
        }
    } else {
        double ave = double(sum) / double(cnt);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(ave < double(a[i][j])) {
                    a[i][j] -= 1;
                } else {
                    a[i][j] += 1;
                }
            }
        }
    }
}
int main() {
    fastio;
    cin >> n >> m >> t;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            valid[i][j] = true;
        }
    }
    
    while(t--) {
        int x, d, k;
        cin >> x >> d >> k;
        for(int i = x - 1; i < n; i += x) {
            turn(a, i, d, k);
        }
        check(a);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(valid[i][j] == false) cout << "x ";
                else cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(valid[i][j] == false) continue;
            ans += a[i][j];
        }
    }
    cout << ans << '\n';

    return 0;
}