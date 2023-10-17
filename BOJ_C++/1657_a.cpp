#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dist[51][51];
int check[5001];
void solve() {
    int x, y;
    cin >> x >> y;
    cout << dist[x][y] << '\n';
}
int main() {
    for(int i = 1; i * i <= 5000; i++) {
        check[i * i] = 1;
    }
    memset(dist,-1,sizeof(dist));
    queue<pii> q;
    q.push({0, 0});
    dist[0][0] = 0;
    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for(int i = 0; i <= 50; i++) {
            for(int j = 0; j <= 50; j++) {
                int d = (x - i) * (x - i) + (y - j) * (y - j);
                if(check[d] && dist[i][j] == -1) {
                    dist[i][j] = dist[x][y] + 1;
                    q.push({i, j});
                }
            }
        }
    }
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}