#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
map<int, int> dp[20][20];
int n,a[20][20];
int go(int x, int y, int now) {
    if(x == n - 1 && y == n - 1) {
        if((now ^ a[x][y]) == 0) return 0;
        return 1e9 + 7;
    }
    if(dp[x][y].count(now)) return dp[x][y][now];
    dp[x][y][now] = 0;

    if(x + 1 < n) {
        int tmp = go(x + 1, y, now ^ a[x][y]);
        if(tmp < 1e9) {
            dp[x][y][now] += tmp + 1;
        } 
    }
    if(y + 1 < n) {
        int tmp = go(x, y + 1, now ^ a[x][y]);
        if(tmp < 1e9) {
            dp[x][y][now] += tmp + 1;
        } 
    }
    return dp[x][y][now];
}
int main() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    cout << go(0,0,0) << '\n';
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << i << ' ' << j << '\n';
            for(auto it = dp[i][j].begin(); it != dp[i][j].end(); it++) {
                cout << it->first << ' ' << it->second << '\n';
            }
            cout << '\n';
        }
    }
    return 0;
}