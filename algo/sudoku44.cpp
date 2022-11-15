#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int a[4][4];
bool row[4][5], col[4][5], sqare[4][5];
void printSudoku() {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return ;
}
bool go(int now) {
    if(now == 16) {
        printSudoku();
        return true;
    }
    int x = now / 4;
    int y = now % 4;
    if(a[x][y]) return go(now + 1);
    else {
        for(int i = 1; i <= 4; i++) {
            if(!row[x][i] && !col[y][i] && !sqare[(x / 2) * 2 + (y / 2)][i]) {
                row[x][i] = col[y][i] = sqare[(x / 2) * 2 + (y / 2)][i] = true;
                a[x][y] = i;
                if(go(now + 1)) return true;
                row[x][i] = col[y][i] = sqare[(x / 2) * 2 + (y / 2)][i] = false;
                a[x][y] = 0;
            }
        }
    }
    return false;
}
void init() {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            a[i][j] = 0;
        }

        for(int j = 0; j < 5; j++) {
            row[i][j] = col[i][j] = sqare[i][j] = false;
        }
    }
}
void solve() {
    init();
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            cin >> a[i][j];
            row[i][a[i][j]] = true;
            col[j][a[i][j]] = true;
            sqare[(i / 2) * 2 + (j / 2)][a[i][j]] = true;
        }
    }

    go(0);
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}