#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int a[6][3];

bool check(int x, int y) {
    if(x == 6) return true;
    if(y == 6) return check(x + 1, x + 2);

    if(a[x][0] && a[y][2]) {
        a[x][0]--; a[y][2]--;
        if(check(x, y + 1)) return true;
        a[x][0]++; a[y][2]++;
    } 
    if(a[x][1] && a[y][1]) {
        a[x][1]--; a[y][1]--;
        if(check(x, y + 1)) return true;
        a[x][1]++; a[y][1]++;
    }
    if(a[x][2] && a[y][0]) {
        a[x][2]--; a[y][0]--;
        if(check(x, y + 1)) return true;
        a[x][2]++; a[y][0]++;
    }
    return false;
}

int main() {
    fastio;
    int tc = 4;
    while(tc--) {

        for(int i = 0; i < 6; i++) {
            for(int j = 0; j < 3; j++) {
                cin >> a[i][j];
            }
        }

        bool sumOk = true;
        for(int i = 0; i < 6; i++) {
            if(a[i][0] + a[i][1] + a[i][2] != 5) sumOk = false;
        }
    
        if(!sumOk) cout << 0 << ' ';
        else {
            if(check(0, 1)) cout << 1 << ' ';
            else cout << 0 << ' ';
        }
    }

    return 0;
}