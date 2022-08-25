#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9;

int d[101][10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;

    for(int i = 1; i <= 9; i++) {
        d[1][i] = 1;
    }

    for(int i = 2; i <= n; i++) {
        d[i][0] = d[i-1][1];
        d[i][9] = d[i-1][8];
        d[i][0] %= MOD;
        d[i][9] %= MOD;
        for(int j = 1; j <= 8; j++) {
            d[i][j] = d[i-1][j-1] + d[i-1][j+1];
            d[i][j] %= MOD;
        }
    }     
    int ans = 0;
    for(int i = 0; i <= 9; i++) {
        ans += d[n][i];
        ans %= MOD;
    }
    cout << ans << '\n';
    return 0;
}