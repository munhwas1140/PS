#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int change(int x) {
    if(x == 0) return 1;
    if(x == 1) return 0;
    if(x == 2) return 3;
    if(x == 3) return 2;
}
int n, m;
int ex, ey;
string a[10];
int dir[10][10];
void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 'O') {
                ex = i;
                ey = j;
                a[i][j] = '.';
            }
        }
    }

    memset(dir,-1,sizeof(dir));
    for(int i = 1; i < n - 1; i++) {
        for(int j = 1; j < m - 1; j++) {
            if(a[i][j] == '.' && dir[i][j] == -1) {
                for(int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    
                }
            }
        }
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