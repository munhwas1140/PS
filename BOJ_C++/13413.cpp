#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    string a, b;
    cin >> a >> b;
    int ab = 0, bb = 0, dif = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == 'B') ab++;
        if(b[i] == 'B') bb++;
        if(a[i] != b[i]) dif++;
    }

    int ans = 0;
    if(ab > bb) {
        ans += ab - bb;
    } else if(ab < bb) {
        ans += bb - ab;
    }
    dif -= ans;
    if(dif == 0) {
        cout << ans << '\n';
    } else {
        cout << ans + dif / 2 << '\n';
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