#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
int psum[1001][1001];
int main() {
    fastio;
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int tmp;
            cin >> tmp;
            psum[i+1][j+1] = psum[i][j+1] + psum[i+1][j] - psum[i][j] + tmp;
        }
    }
    
    while(q--) {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int t1 = psum[x2][y2] - psum[x2][y1-1] - psum[x1-1][y2] + psum[x1-1][y1-1];
        int t2 = (y2 - y1 + 1) * (x2 - x1 + 1);
        cout << t1 / t2 << '\n';
    }
    return 0;
}