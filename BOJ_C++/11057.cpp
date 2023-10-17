#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e4 + 7;
int d[1001][10];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;

    for(int i = 0; i <= 9; i++) {
        d[1][i] = 1;
    } 
    
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= 9; j++) {
            for(int k = 0; k <= j; k++) {
                d[i][j] += d[i-1][k];
            }
            d[i][j] %= mod;
        }
    }

    int ans = 0;

    for(int i = 0; i <= 9; i++) {
        ans += d[n][i];
        ans %= mod;
    } 

    cout << ans << '\n';
    return 0;
}