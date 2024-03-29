#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    ll n, k;
    cin >> n >> k;
    if(n % k == 0) cout << 0 << '\n';
    else {
        ll g = gcd(n, k);
        n /= g;
        k /= g;
        cout << n * (min(n - k, k) - 1) << '\n';
    }
    return 0;
}