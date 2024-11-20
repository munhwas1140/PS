#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    ll n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    map<ll, ll> mp;

    for(ll i = 0; i < n; i++) {
        ll tmp = 0;
        tmp += i + (n - i - 1);
        tmp += i * (n - i - 1);
        mp[tmp] += 1;
    }
    for(ll i = 0; i < n - 1; i++) {
        ll tmp = 1LL;
        tmp += i + (n - i - 2);
        tmp += i * (n - i - 2);
        mp[tmp] += a[i + 1] - a[i] - 1;
    }
    for(int i = 0; i < q; i++) {
        ll x; cin >> x;
        cout << mp[x] << ' ';
    }
    cout << '\n';

}
int main() {
    fastio;
    int tc; cin >> tc; 
    while(tc--) {
        solve();
    }
    return 0;
}

