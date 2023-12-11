#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
ll n, p, q, x, y;
map<ll, ll> mp;
ll go(ll now) {
    if(now <= 0) return 1;

    if(mp.count(now)) return mp[now];

    mp[now] = go((now / p) - x) + go((now / q) - y);
    return mp[now];
}
int main() {
    fastio;
    cin >> n >> p >> q >> x >> y;
    cout << go(n) << '\n';
    return 0;
}