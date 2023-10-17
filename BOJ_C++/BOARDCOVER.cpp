#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
int coverType[4][3][2] = {
    {{0,0}, {1,0}, {0,1}},
    {{0,0}, {0,1}, {1,1}},
    {{0,0}, {1,0}, {1,1}},
    {{0,0}, {1,0}, {1,-1}}
};
bool go(vector<vector<int>> &a, int x, int y, int type, int val) {
    bool ok = true;
    for(int i = 0; i < 3; i++) {
        int nx = x + coverType[type][i][0];
        int ny = y + coverType[type][i][1];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) ok = false;
        else if((a[nx][ny] += val) > 1) {
            ok = false;
        }
    }
    return ok;
}
int cover(vector<vector<int>> &a) {
    int x, y;
    x = y = -1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 0) {
                x = i; y = j;
                break;
            }
        }
        if(y != -1) break;
    }

    if(y == -1) return 1;
    int ret = 0;
    for(int i = 0; i < 4; i++) {
        if(go(a, x, y, i, 1)) {
            ret += cover(a);
        }
        go(a, x, y, i, -1);
    }
    return ret;
}
void solve() {
    cin >> n >> m;
    vector<string> tmp(n);
    vector<vector<int>> a(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) cin >> tmp[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(tmp[i][j] == '#') a[i][j] = 1;
            else a[i][j] = 0;
        }
    }
    cout << cover(a) << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}