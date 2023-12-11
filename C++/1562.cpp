#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

const ll mod = 1e9;
int n;
ll d[101][10][1<<10];
int main() {
    fastio;
    cin >> n;
    for(int i = 1; i < 10; i++) {
        d[1][i][1<<i] = 1;
    }
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < (1 << 10); j++) {
            d[i][0][j|(1<<0)] += d[i-1][1][j];
            d[i][9][j|(1<<9)] += d[i-1][8][j];
            d[i][0][j|(1<<0)] %= mod;
            d[i][9][j|(1<<9)] %= mod;
            for(int k = 1; k < 9; k++) {
                d[i][k][j|(1<<k)] += d[i-1][k-1][j];
                d[i][k][j|(1<<k)] += d[i-1][k+1][j];
                d[i][k][j|(1<<k)] %= mod;
            }
        }
    }
      
    ll ans = 0;
    for(int i = 0; i < 10; i++) {
        ans = (ans + d[n][i][(1 << 10) - 1]) % mod;
    }
    cout << ans << '\n';
    return 0;
}