#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
bool visited[5][5];
int n, m, k;
vector<string> a;

int go(int x, int y, int dist) {
    if(x == 0 && y == m - 1) {
        if(dist == k - 1) return 1;
        return 0;
    } 
    visited[x][y] = true;
    int ret = 0;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(a[nx][ny] == 'T') continue;
        if(!visited[nx][ny] && dist < k - 1) {
            visited[nx][ny] = true;
            ret += go(nx, ny, dist + 1);
            visited[nx][ny] = false;
        }
    }
    return ret;
}
int main() {
    fastio;
    cin >> n >> m >> k;
    a.resize(n);
    for(auto &s : a) cin >> s;

    cout << go(n-1,0,0) << '\n';

    return 0;
}