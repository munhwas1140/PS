#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int a[50][50];
int p[251];
int dist[50][50];
int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}
void set_union(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    p[x] = y;
}
int n, m;
int main() {
    fastio;
    cin >> n >> m;
    vector<string> tmp(n);
    vector<pii> pos;
    int cnt = 0;
    memset(a,-1,sizeof(a));
    for(int i = 0; i < n; i++) {
        cin >> tmp[i];
        for(int j = 0; j < n; j++) {
            if(tmp[i][j] == '1') a[i][j] = -2;
            else if(tmp[i][j] == 'K') {
                pos.push_back({i, j});
                a[i][j] = ++cnt;
            } else if(tmp[i][j] == 'S') {
                pos.insert(pos.begin(), make_pair(i, j));
                a[i][j] = 0;
            }
        }
    }

    priority_queue<tuple<int, int, int>> pq;
    queue<pii> q;
    for(int i = 0; i <= m; i++) {
        memset(dist,-1,sizeof(dist));
        dist[pos[i].first][pos[i].second] = 0;
        q.push({pos[i].first, pos[i].second});
        
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if(a[nx][ny] == -2) continue;
                if(dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    if(a[nx][ny] >= 0) {
                        pq.push({-dist[nx][ny], i, a[nx][ny]});
                    }
                    q.push({nx, ny});
                }
            }
        }
    }

    int c = 0;
    int ans = 0;
    memset(p,-1,sizeof(p));
    while(!pq.empty() && c < m) {
        auto [d, x, y] = pq.top();
        pq.pop();
        d = -d;
        x = find(x);
        y = find(y);
        if(x != y) {
            set_union(x, y);
            c++;
            ans += d;
        }
    }
    if(ans == 0 || c != m) cout << -1 << '\n';
    else cout << ans << '\n';
    
    return 0;
}