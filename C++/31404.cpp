#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
string a[100], b[100];
bool visited[64][64][4];
bool check[64][64];
int n, m, ans = 0;
bool dfs(int x, int y, int d) {
    if(x < 0 || x >= n || y < 0 || y >= m) return false;
    int nd;
    bool f = false;
    if(!check[x][y]) {
        check[x][y] = true;
        f = true;
        nd = (d + (a[x][y] - '0')) % 4;
        memset(visited, 0, sizeof(visited));
    } else {
        if(!visited[x][y][d]) {
            visited[x][y][d] = true;
        } else {
            return false;
        }
        nd = (d + (b[x][y] - '0')) % 4;
    }
    ans++;

    if(!dfs(x + dx[nd], y + dy[nd], nd) && !f) {
        ans--;
        return false;
    }
    return true;

}
int main() {
    fastio;
    int x, y, d;
    cin >> n >> m;
    cin >> x >> y >> d;

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    dfs(x, y, d);
    cout << ans << '\n';

    return 0;
}