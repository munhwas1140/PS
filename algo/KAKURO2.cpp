#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, color[20][20], value[20][20], hint[20][20][2];
int candidates[10][46][1024];
int q, sum[20 * 20], length[20 * 20], known[20 * 20];
int getLen(int x) {
    int len = 0;
    for(int i = 1; i <= 9; i++) {
        if(x & (1 << i)) len++;
    }
    return len;
}
int getSum(int x) {
    int sum = 0;
    for(int i = 1; i <= 9; i++) {
        if(x & (1 << i)) sum += i;
    }
    return sum;
}
void put(int x, int y, int val) {
    for(int h = 0; h < 2; h++) {
        known[hint[x][y][h]] += (1 << val);
    }
    value[x][y] = val;
}
void remove(int x, int y, int val) {
    for(int h = 0; h < 2; h++) {
        known[hint[x][y][h]] -= (1 << val);
    }
    value[x][y] = 0;
}
int getCandHint(int hint) {
    return candidates[length[hint]][sum[hint]][known[hint]];
}
int getCandCoord(int x, int y) {
    return getCandHint(hint[x][y][0]) & getCandHint(hint[x][y][1]);
}
void printSolution() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << value[i][j] << ' ';
        }
        cout << '\n';
    }
}
bool search() {
    int x = -1, y = -1;
    int minCands = 1023;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(color[i][j] == 1 && value[i][j] == 0) {
                int cands = getCandCoord(i, j);
                if(getLen(minCands) > getLen(cands)) {
                    minCands = cands;
                    x = i;
                    y = j;
                }
            }
        }
    }
    if(minCands == 0) return false;
    if(x == -1) {
        printSolution();
        return true;
    }
    
    for(int val = 1; val <= 9; val++) {
        if(minCands & (1 << val)) {
            put(x, y, val);
            if(search()) return true;
            remove(x, y, val);
        }
    }

    return false;
}
void generate() {
    memset(candidates,0,sizeof(candidates));
    
    for(int i = 0; i < 1024; i += 2) {
        int l = getLen(i), s = getSum(i);
        int subset = i;
        while(true) {
            candidates[l][s][subset] |= (i & ~subset);
            if(subset == 0) break;
            subset = (subset - 1) & i;
        }
    }
}
void init() {
    memset(color, 0, sizeof(color));
    memset(hint, 0, sizeof(hint));
    memset(value, 0, sizeof(value));
    memset(length, 0, sizeof(length));
    memset(sum, 0, sizeof(sum));
    memset(known, 0, sizeof(known));
}
void solve() {
    init();

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> color[i][j];
        }
    }

    cin >> q;
    for(int i = 0; i < q; i++) {
        int x, y, h, val;
        cin >> x >> y >> h >> val;
        x--;
        y--;
        hint[x][y][h] = i;
        sum[hint[x][y][h]] = val;
        int dx = 0, dy = 0;
        if(h) dx = 1;
        else dy = 1;
        int nx = x + dx;
        int ny = y + dy;
        int l = 0;
        while(true) {
            if(nx >= n || ny >= n) break;
            if(color[nx][ny] == 0) break;
            hint[nx][ny][h] = i;
            l++;
            nx += dx;
            ny += dy;
        }
        length[hint[x][y][h]] = l;

    }

    search();
}
int main() {
    fastio;

    generate();
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}