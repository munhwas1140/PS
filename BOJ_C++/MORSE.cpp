#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
ll comb[201][201];
const ll MAX = 1e9 + 100;
string go(int n, int m, int skip) {
    if(n == 0) {
        return string(m, 'o');
    }

    if(skip < comb[n + m - 1][n - 1]) {
        return "-" + go(n - 1, m, skip);
    } else {
        return "o" + go(n, m - 1, skip - comb[n + m - 1][n - 1]);
    }
}
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    k--;
    cout << go(n, m, k) << '\n';
}

int main() {
    fastio;
    for(int i = 0; i <= 200; i++) {
        for(int j = 0; j <= i; j++) {
            if(j == 0 || i == j) {
                comb[i][j] = 1;
            } else {
                comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
            }
            comb[i][j] = min(comb[i][j], MAX);
        }
    }

    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}