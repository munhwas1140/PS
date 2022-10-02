#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int a[100][100];
int rsum[100];
int csum[100];
int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            rsum[i] += a[i][j];
            csum[j] += a[i][j];
        }
    }

    int ans = -1e9 + 7;
    for(int r1 = 0; r1 < n; r1++) {
        for(int r2 = r1 + 1; r2 < n; r2++) {
            for(int c1 = 0; c1 < m; c1++) {
                for(int c2 = c1 + 1; c2 < m; c2++) {
                    int tmp = 0;
                    tmp += rsum[r1] + rsum[r2];
                    tmp += csum[c1] + csum[c2];
                    tmp -= a[r1][c1] + a[r1][c2] + a[r2][c1] + a[r2][c2];
                    tmp += (r2 - r1 - 1) * (c2 - c1 - 1);
                    ans = max(ans, tmp);
                }
            }
        }
    }
    cout << ans << '\n';
    

    return 0;
}