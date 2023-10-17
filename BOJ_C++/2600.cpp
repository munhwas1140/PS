#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int b[3];
int dp[501][501];
int go(int x, int y) {
    
    int &ret = dp[x][y];
    if(ret != -2) return ret;

    int tmp = 1;
    for(int i = 0; i < 3; i++) {
        if(x >= b[i]) tmp = min(tmp, go(x - b[i], y));
        if(y >= b[i]) tmp = min(tmp, go(x, y - b[i]));
    }
    if(tmp == 1) return ret = -1;
    return ret = 1;
}
void solve() {
    int a, b;
    cin >> a >> b;
    for(int i = 0; i < 501; i++) {
        for(int j = 0; j < 501; j++) {
            dp[i][j] = -2;
        }
    }

    int ans = go(a, b);

    if(ans == 1) cout << "A" << '\n';
    else cout << "B" << '\n';
}
int main() {
    fastio;
    for(int i = 0; i < 3; i++) cin >> b[i];
    int tc = 5;
    while(tc--) {
        solve();
    }
    return 0;
}