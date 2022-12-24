#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
int a[1025][1025];
int tree[1025][1025];
void update(int x, int y, int val) {
    for(int row = x; row <= n; row += (row & -row)) {
        for(int col = y; col <= n; col += (col & -col)) {
            tree[row][col] += val;
        }
    }
}
int query(int x, int y) {
    int ret = 0;
    for(int row = x; row > 0; row -= (row & -row)) {
        for(int col = y; col > 0; col -= (col & -col)) {
            ret += tree[row][col];
        }
    }
    return ret;
}
int query(int x1, int y1, int x2, int y2) {
    return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
}
int main() {
    fastio;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
            update(i, j, a[i][j]);
        }
    }

    int q, x1, y1, x2, y2, num;
    while(m--) {
        cin >> q;
        if(q == 0) {
            cin >> x1 >> y1 >> num;
            update(x1, y1, num - a[x1][y1]);
            a[x1][y1] = num;
        } else {
            cin >> x1 >> y1 >> x2 >> y2;
            if(x1 > x2) swap(x1, x2);
            if(y1 > y2) swap(y1, y2);
            cout << query(x1,y1,x2,y2) << '\n';
        }
    }

    return 0;
}