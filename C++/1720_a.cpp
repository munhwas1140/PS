#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    a *= d;
    b *= c;
    if(a == b) cout << 0 << '\n';
    else {
        if(a == 0 || b == 0) cout << 1 << '\n';
        else if(a % b == 0 || b % a == 0) cout << 1 << '\n';
        else cout << 2 << '\n';
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