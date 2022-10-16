#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int to(char x) {
    if(x == 'L') return 1;
    if(x == 'U') return 3;
    if(x == 'D') return 2;
    return 0;
}
map<int,set<int>> row, col;
int main() {
    fastio;
    int x, y, k;
    cin >> n >> m >> x >> y;
    cin >> k;
    for(int i = 0; i < k; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        row[t1].insert(t2);
        col[t2].insert(t1);
    }

    int q; cin >> q;
    while(q--) {
        char d;
        int i;
        cin >> d >> i;

        int dir = to(d);

        int nx = x + dx[dir] * i;
        int ny = y + dy[dir] * i;
        
        if(nx > n) nx = n;
        if(nx <= 0) nx = 1;
        if(ny > m) ny = m;
        if(ny <= 0) ny = 1;

        if(dir == 2 || dir == 3) {
            //col check
            auto it = col[y].lower_bound(x);
            if(dir == 2) {
                //down
                if(it != col[y].end() && *it <= nx) {
                    x = *it - 1;
                } else x = nx;
            }
            if(dir == 3) {
                //up
                if(col[y].size() == 0 || it == col[y].begin()) {
                    x = nx;
                } else {
                    it--;
                    x = max(*it + 1, nx);
                }
            }
        } else {
            //row check
            auto it = row[x].lower_bound(y);
            if(dir == 0) {
                //right
                if(it != row[x].end() && *it <= ny) {
                    y = *it - 1;
                } else y = ny;
            }
            if(dir == 1) {
                //left
                if(row[x].size() == 0 || it == row[x].begin()) {
                    y = ny;
                } else {
                    it--;
                    y = max(ny, *it + 1);
                }
            }
        }
        cout << x << ' ' << y << '\n';
    }

    return 0;
}