#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int a[30];
void solve() {
    int q, x;
    cin >> q >> x;
    if(q == 1) {
        a[x]++;
    } else {
        int now = 0;
        for(int i = 0; i < 30; i++) {
            now += a[i];
            bool k = (x & (1 << i));
            if(k) {
                if(now == 0) {
                    cout << "NO" << '\n';
                    return;
                }
                now--;
            }
            now /= 2;
        }
        cout << "YES" << '\n';
    }
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}