#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

ll calc(pair<ll, ll> &a, pair<ll, ll> &b, pair<ll, ll> &c) {
    ll x1 = b.first - a.first;
    ll y1 = b.second - a.second;
    ll x2 = c.first - a.first;
    ll y2 = c.second - c.second;
    
    return x1*y2 - x2*y1;
}
int main() {
    fastio;
    int n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }     

    ll ans = 0;

    for(int i = 1; i < n - 1; i++) {
        ans += calc(a[0], a[i], a[i+1]);
    }
    ans = abs(ans);
    cout << ans / 2 << '.';
    if(ans % 2) cout << '5';
    else cout << '0';
    return 0;
}