#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m, r;
int a[500][500];
int lis[500][100000];
void go(int x, int y) {
    if(x >= n / 2 || y >= m / 2) return ;
    
    int cnt = 0;
    for(int i = 0; i < m - 2 * y; i++) {
        lis[x][cnt++] = a[x][y + i];
    }
    for(int i = 1; i < n - 2 * x; i++) {
        lis[x][cnt++] = a[x + i][y + m - 2 * y - 1];
    }
    for(int i = 1; i < m - 2 * y; i++) {
        lis[x][cnt++] = a[x + n - 2 * x - 1][y + m - 2 * y - 1 - i];
    }
    for(int i = 1; i < n - 2 * y - 1; i++) {
        lis[x][cnt++] = a[x + n - 2 * x - 1 - i][y];
    }
    go(x + 1, y + 1);
}

void make(int x, int y) {

    if(x >= n / 2 || y >= m / 2) return ;
    int sz = (n - x * 2) * 2 + (m - y * 2) * 2 - 4;
    int rotnum = (r % sz);
    rotate(lis[x], lis[x] + rotnum, lis[x] + sz);

    int cnt = 0;
    for(int i = 0; i < m - 2 * y; i++) {
        a[x][y + i] = lis[x][cnt++];
    }
    for(int i = 1; i < n - 2 * x; i++) {
        a[x + i][y + m - 2 * y - 1] = lis[x][cnt++];
    }
    for(int i = 1; i < m - 2 * y; i++) {
        a[x + n - 2 * x - 1][y + m - 2 * y - 1 - i] = lis[x][cnt++];
    }
    for(int i = 1; i < n - 2 * y - 1; i++) {
        a[x + n - 2 * x - 1 - i][y] = lis[x][cnt++];
    }
    make(x + 1, y + 1);
}
int main() {
    fastio;
    cin >> n >> m >> r;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    go(0, 0);
    // 11 10 7 6
    make(0, 0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}