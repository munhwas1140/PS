#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    int ans = -1;
    if(a[0] == a[n - 1]) ans = a[0];
    else if((a[0] + a[n - 1]) % 2) ans = gcd(a[0], a[ n - 1]);
    else ans = (a[0] + a[n - 1]) / 2;

    for(int i = 1; i < n / 2; i++) {
        if(a[i] % ans == a[n - 1 - i] % ans) continue;

        if((a[i] + a[n - 1 - i]) % 2) ans = gcd(ans, gcd(a[i], a[n - 1 - i]));
        else ans = gcd(ans, (a[i] + a[n - 1 - i]) / 2);
    }
    cout << ans << '\n';
}

// odd b - a, gcd(a, b)

// even (a + b) / 2, gcd(a, b), b - a
9 24
15
1 9
8 5 1
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}