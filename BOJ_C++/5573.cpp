#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m, k;
int a[1010][1010];
void dfs(int x, int y) {
    if(x >= n + 1 || y >= m + 1) return ;
    if(a[x][y] == 1) {
        a[x][y] = 0;
        dfs(x, y + 1);
    } else {
        a[x][y] = 1;
        dfs(x + 1, y);
    }
}
int main() {
    fastio;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }


    for(int i = 0; i < 20; i++) {
        for(int x = 1; x <= n; x++) {
            for(int y = 1; y <= m; y++) {
                cout << a[x][y] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
        dfs(1, 1);
    }
    return 0;
}