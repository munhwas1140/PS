#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
int a[16][16];
void go(int x, int y, int sz) {
    if(sz < 0) return ;
    for(int i = 0; i < sz; i++) {
        a[x+i][y] = 1;
        a[x+i][y+sz - 1] = 1;
        a[x][y+i] = 1;
        a[x+sz - 1][y+i] = 1;
    }
    go(x + 2, y + 2, sz - 4);
    return ;
}
int main() {
    fastio;
    int r, c;
    cin >> r >> c;
    
    go(1,1,15);

    cout << (a[r][c] ? "black" : "white") << '\n';

    return 0;
}