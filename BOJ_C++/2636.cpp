#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int pre;
    int t = 0;
    while(true) {
        vector<vector<bool>> visited(n, vector<bool>(m));
        queue<pii> q;
        q.push({0, 0});
        vector<pii> cheese;
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if(a[x][y] == 1) {
                cheese.push_back({x ,y});
                continue;
            }

            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(!visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        
        t++;
        if(cheese.size() == 0) break;
        pre = cheese.size();
        for(auto [x, y] : cheese) {
            a[x][y] = 0;
        }
    }
    cout << t - 1 << '\n';
    cout << pre << '\n';

    return 0;
}