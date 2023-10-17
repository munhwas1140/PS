#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int a, b;
    cin >> a >> b;
    if((a % 2 && b % 2) || (a % 2 == 0 && b % 2 == 0)) {
        cout << "Tonya" << '\n';
    } else {
        cout << "Burenka" << '\n';
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