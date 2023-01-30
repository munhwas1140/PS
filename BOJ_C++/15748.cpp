#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    ll n, l, f1, f2;
    cin >> l >> n >> f1 >> f2;
    vector<pll> a(n);
    for(auto &[x, t] : a) {
        cin >> x >> t;
    }
    sort(a.begin(), a.end(), [] (const pll &u, const pll &v) {
        if(u.second == v.second) return u.first > v.first;
        return u.second > v.second;
    });

    
    ll ans = 0, past = 0;
    for(auto &[x, t] : a) {
        if(x <= past) continue;
        ans += (x - past) * (f1 - f2) * t;
        past = x;
    }

    cout << ans << '\n';
    
    return 0;
}