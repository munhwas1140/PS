#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};
void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = 0; j < m; j++) {
            if(a[i][j] == '1') cnt++;
        }
    }

    if(cnt == 0) {
        cout << 0 << '\n';
        return ;
    }
    
    bool ok1, ok2;
    ok1 = ok2 = false;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == '0') {
                ok1 = true;
                for(int k = 0; k < 8; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(a[nx][ny] == '0') ok2 = true;
                }
            }
        }
    }

    if(ok2) {
        cout << cnt << '\n';
    } else if(ok1) {
        cout << max(cnt - 1, 1) << '\n';
    } else {
        cout << max(cnt - 2, 1) << '\n';
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