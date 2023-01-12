#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    if(n % 2 == 1) {
        cout << 1 << ' ';
        for(int i = 2; i <= n; i += 2) {
            cout << i + 1 << ' ' << i << ' ';
        }
    } else {
        for(int i = 1; i <= n; i += 2) {
            cout << i + 1 << ' ' << i << ' ';
        }
    }
    cout << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}