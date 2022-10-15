#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MAX = 1e9 + 100;
int C[201][201];
string go(int n, int m, int k) {
    if(n == 0) return string(m, 'o');
    if(k < C[n + m - 1][n - 1]) {
        return "-" + go(n - 1, m, k);
    } else return "o" + go(n, m - 1, k - C[n + m - 1][n - 1]);
}
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    cout << go(n, m, k - 1) << '\n';
}
int main() {
    fastio;
    for(int i = 0; i <= 200; i++) {
        for(int j = 0; j <= i; j++) {
            if(j == 0 || i == j) C[i][j] = 1;
            else {
                C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
                C[i][j] = min(MAX, C[i][j]);
            }
        }
    }
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}