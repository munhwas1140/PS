#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int psum[200001][30];
void solve() {
    int l, r; cin >> l >> r;
    int n = r - l + 1;
    int cnt = 0;
    for(int i = 0; i < 30; i++) {
        cnt = max(cnt, psum[r][i] - psum[l - 1][i]);
    }
    cout << n - cnt << '\n';
}
int main() {
    fastio;
    for(int i = 1; i <= 200000; i++) {
        for(int j = 0; j < 30; j++) {
            psum[i][j] = psum[i - 1][j];
            if(i & (1 << j)) {
                psum[i][j]++;
            }
        }
    }

    int tc; cin >> tc;
    while(tc--) {
        solve();
    }

    
    return 0;
}