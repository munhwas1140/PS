#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};
int main() {
    fastio;
    int n; cin >> n;
    vector<string> a(n);
    vector<vector<int>> h(n, vector<int>(n));
    vector<int> pos;
    int sx, sy;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = 0; j < n; j++) {
            if(a[i][j] == 'P') {
                sx = i;
                sy = j;
            } else if(a[i][j] == 'K') {
                cnt++;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> h[i][j];
            pos.push_back(h[i][j]);
        }
    }
    
    sort(pos.begin(), pos.end());
    pos.erase(unique(pos.begin(), pos.end()), pos.end());

    function<bool(int, int)> bfs = [&] (int s, int e) {
        int ret = 0;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pii> q;
        q.push({sx, sy});
        visited[sx][sy] = true;
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if(a[x][y] == 'K') ret++;
            
            for(int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if(!visited[nx][ny] && s <= h[nx][ny] && h[nx][ny] <= e) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
        return ret == cnt;
    };
    int ans = 1e9;
    int s = 0, e = 0;
    while(s <= e && e < pos.size()) {
        if(h[sx][sy] < pos[s] || pos[e] < h[sx][sy]) {
            e++;
            continue;
        }

        if(bfs(pos[s], pos[e])) {
            ans = min(ans, pos[e] - pos[s]);
            s++;
        } else {
            e++;
        }
    }
    
    cout << ans << '\n';
    return 0;
}