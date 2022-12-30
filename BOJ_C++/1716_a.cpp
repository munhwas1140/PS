#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    if(n == 1) {
        cout << 2 << '\n';
    } else if(n % 3 == 0) cout << n / 3 << '\n';
    else if((n - 2) % 3 == 0) cout << (n - 2) / 3 + 1 << '\n';
    else if((n - 4) % 3 == 0) cout << (n - 4) / 3 + 2 << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}