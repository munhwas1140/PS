#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int a[9][9];
bool row[9][10];
bool col[9][10];
bool rec[9][10];
bool go(int x, int y ) {
    if(y == 9) return go(x + 1, 0);
    if(x == 9) return true;
    
    if(a[x][y] != 0) return go(x, y + 1);
    else {
        for(int i = 1; i <= 9; i++) {
            if(!row[x][i] && !col[y][i] && !rec[x/3*3+y/3][i]) {
                row[x][i] = col[y][i] = rec[x/3*3+y/3][i] = true;
                a[x][y] = i;
                if(go(x, y + 1)) return true;
                row[x][i] = col[y][i] = rec[x/3*3+y/3][i] = false;
            }
        }
        a[x][y] = 0;
    }
    return false;
}
int main() {
    fastio;
         
    for(int i = 0; i < 9; i ++) {
        for(int j = 0; j < 9; j++) {
            cin >> a[i][j];
            if(a[i][j] != 0) {
                row[i][a[i][j]] = true;
                col[j][a[i][j]] = true;
                rec[i/3*3+j/3][a[i][j]] = true;
            }
        }
    }

    go(0,0); 

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}