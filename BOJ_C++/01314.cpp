#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int dist[70][70];
int main() {
    fastio;
    int n;
    cin >> n; 
    int ans = 0;
    memset(dist,-1,sizeof(dist));
    queue<pair<int,int>> q;
    dist[35][35] = n;
    q.push({35, 35});
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(dist[x][y] == 0 || dist[x][y] % 2 == 0) {
            ans++;
            if(dist[x][y] == 0) continue;
        }
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] - 1;
                q.push({nx, ny});
            }
        }
    }

    cout << ans << '\n';
    return 0;
}