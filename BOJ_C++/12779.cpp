#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    ll a, b;
    cin >> a >> b;
    ll l = ceil(sqrt(a + 1));
    ll r = floor(sqrt(b));

    ll u = r - l + 1;
    ll d = b - a;
    if(u == 0) cout << 0 << '\n';
    else {
        ll GCD = gcd(u, d);
        cout << u / GCD << '/' << d / GCD << '\n';
    }
    return 0;
}