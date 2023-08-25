#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
map<ll,ll> mp;
void init() {
    mp[1] = 1;
    for(int i = 2; pow(2, i) - 1 <= 1e16; i++) {
        ll t1 = pow(2, i);
        ll t2 = pow(2, i - 1);
        mp[t1 - 1] = t2 + 2 * mp[t2 - 1];
    }
}

ll g(ll x) {
    if(x <= 0) return 0LL;

    ll idx = 0;
    for(int i = 0; ;i++) {
        if(pow(2, i) - 1 > x) {
            idx = i - 1;
            break;
        }
    }

    ll tmp = pow(2, idx) - 1;
    if(tmp == x) {
        return mp[tmp];
    } else {
        return mp[tmp] + (x - tmp) + g(x - tmp - 1);
    }
}
int main() {
    fastio;
    ll a, b;
    cin >> a >> b;

    init();
    cout << g(b) - g(a - 1) << '\n';
    return 0;
}