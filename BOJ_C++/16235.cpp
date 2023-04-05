#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};
deque<int> tr[10][10];
int main() {
    fastio;
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(n, 5));
    vector<vector<int>> c(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }


    for(int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--; y--;
        tr[x][y].push_back(z);
    }
    


    for(int t = 0; t < k; t++) {
        queue<pair<int,int>> grow;
        queue<tuple<int,int,int>> death;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(tr[i][j].empty()) continue;
                int sz = tr[i][j].size();
                sort(tr[i][j].begin(), tr[i][j].end());

                for(int k = 0; k < sz; k++) {
                    int now = tr[i][j].front();
                    tr[i][j].pop_front();
                    if(a[i][j] >= now) {
                        a[i][j] -= now;
                        now++;
                        if(now % 5 == 0) grow.push({i, j});
                        tr[i][j].push_back(now);
                    } else {
                        death.push({i, j, now});
                    }
                }
            }
        }
        
        while(!death.empty()) {
            auto [x, y, z] = death.front();
            death.pop();
            a[x][y] += z / 2;
        }
        

        while(!grow.empty()) {
            auto [x, y] = grow.front();
            grow.pop();
            for(int k = 0; k < 8; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                tr[nx][ny].push_back(1);
            }
        }
        for(int x = 0; x < n; x++) {
            for(int y = 0; y < n; y++) {
                a[x][y] += c[x][y];
            }
        }
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ans += tr[i][j].size();
        }
    }

    cout << ans << '\n';

    return 0;
}