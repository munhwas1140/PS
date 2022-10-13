#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};
bool visited[5][5];
bool go(vector<string> &a, string &str, int x, int y, int idx) {
    if(a[x][y] != str[idx]) return false;
    if(idx == str.size() - 1) return true;

    visited[x][y] = true;
    for(int k = 0; k < 8; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
        if(!visited[nx][ny] && go(a, str, nx, ny, idx + 1)) return true;
    }
    visited[x][y] = false;
    return false;
}
void solve() {
    vector<string> a(5);
    for(int i = 0; i < 5; i++) {
        cin >> a[i];
    }
    int n; cin >> n;
    while(n--) {
        string str; cin >> str;
        memset(visited,false,sizeof(visited));
        bool ok = false;
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                if(go(a, str, i, j, 0)) {
                    ok = true;
                    break;
                }
            }
            if(ok) break;
        }
        cout << str << ' ';
        if(ok) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }

    return 0;
}