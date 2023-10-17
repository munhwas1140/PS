#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
ll x, k;
int main() {
    fastio;
    cin >> x >> k;
    ll now = 1, ans = 0;
    while(k) {
        while(now & x) now <<= 1;
        if(k % 2) ans |= now;
        k /= 2;
        now <<= 1;
    }
    cout << ans << '\n';
    return 0;
}