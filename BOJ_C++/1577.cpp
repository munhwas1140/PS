#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
bool pos[101][101][2];
ll dp[101][101];
ll go(int x, int y) {
    if(x == 1 && y == 1) return 1LL;
    ll &ret = dp[x][y];
    if(ret != -1) return ret;
    ret = 0;

    if(x > 1 && !pos[x][y][0]) {
        ret += go(x - 1, y);
    }
    if(y > 1 && !pos[x][y][1]) {
        ret += go(x, y - 1);
    }
    return ret;
}
int main() {
    fastio;
    cin >> n >> m;
    int k; cin >> k;
    while(k--) {
        int t1, t2, t3, t4;
        cin >> t1 >> t2 >> t3 >> t4;
        t1++; t2++; t3++; t4++;
        if(t1 != t3) {
            if(t1 > t3) {
                pos[t1][t2][0] = true;
            } else pos[t3][t4][0] = true;

        } else if(t2 != t4) {
            if(t2 > t4) {
                pos[t1][t2][1] = true;
            } else pos[t3][t4][1] = true;

        }
    }

    memset(dp,-1,sizeof(dp));
    cout << go(n + 1, m + 1) << '\n';

    return 0;
}