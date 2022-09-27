#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;

int n, k;
ll dist(pll &a, pll &b) {
    ll t1 = a.first - b.first;
    ll t2 = a.second - b.second;
    return t1 * t1 + t2 * t2;
}
int main() {
    fastio;
    cin >> n >> k;
    vector<int> pos(k);
    vector<pll> a(n + 1);
    for(int i = 0; i < k; i++) {
        cin >> pos[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ll mm = 8e18;
        for(int j = 0; j < k; j++) {
            ll tmp = dist(a[i], a[pos[j]]);
            mm = min(mm, tmp);
        }
        ans = max(ans, mm);
    }

    cout << fixed << setprecision(15) << sqrt(ans) << '\n';

    return 0;
}