#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = -1;
    for(int i = 0; i <= 30; i++) {
        for(int j = 0; j <= 30; j++) {
            for(int k = 0; k <= 30; k++) {
                int t1, t2, t3;
                t1 = a; t2 = b; t3 = c;
                t1 -= i; t2 -= i;
                t1 -= j; t3 -= j;
                t2 -= k; t3 -= k;
                if(t1 < 0 || t2 < 0 || t3 < 0) continue;
                if(t1 % 2 || t2 % 2 || t3 % 2) continue;
                ans = max(ans, i + j + k);
            }
        }
    }
    cout << ans << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}
