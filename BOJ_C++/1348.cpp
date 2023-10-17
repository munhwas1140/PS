#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m, MAP[51][51], pnum;
string a[51];
vector<pii> cars;
vector<pair<int,int>> g[2501];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int dist[51][51];
void solve() {
    cin >> n >> m;
    memset(MAP,-1,sizeof(MAP));
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 'C') cars.push_back({i, j});
            else if(a[i][j] == 'P') MAP[i][j] = ++pnum;
        } 
    }

    for(int i = 0; i < cars.size(); i++) {
        memset(dist,-1,sizeof(dist));
        dist[cars[i].first][cars[i].second] = 0;
        queue<pii> q;
        q.push({cars[i].first, cars[i].second});
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if(a[x][y] == 'P') {
                g[i + 1].push_back({MAP[x][y], dist[x][y]});
            }
            for(int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(a[nx][ny] == 'X') continue;
                if(dist[nx][ny] != -1) continue;
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    if(cars.size() == 0) {
        cout << 0 << '\n';
    } else {
    
    }
    
    return ;
}
int main() {
    fastio;
    solve();
    return 0;
}