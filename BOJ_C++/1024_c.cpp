#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
bool a[2][200];
int main() {
    fastio;
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) {
        int t; cin >> t;
        a[0][t] = 1;
    }

    for(int i = 1; i <= k; i++) {
        for(int j = 0; j < n; j++) {
            a[(i % 2)][j] = 0;
        }
        for(int j = 0; j < n; j++) {
            if(a[(i % 2) ^ 1][j]) {
                a[i % 2][(j + 1) % n] ^= 1;
                a[i % 2][(j - 1 + n) % n] ^= 1;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += a[(k % 2)][i];
    }
    cout << ans << '\n';

    return 0;
}