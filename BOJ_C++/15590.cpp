#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n, m, r;
    cin >> n >> m >> r;

    vector<ll> a(n);
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
    
    vector<pll> b(m);
    vector<pll> psum(m);
    for(auto &[p, q] : b) cin >> q >> p;
    sort(b.rbegin(), b.rend());
    for(int i = 0; i < m; i++) {
        if(i == 0) psum[i] = {b[i].second, b[i].first * b[i].second};
        else {
            psum[i] = {psum[i - 1].first + b[i].second, psum[i - 1].second + b[i].first * b[i].second};
        }
    }

    vector<ll> c(r);
    for(int i = 0; i < r; i++) {
        cin >> c[i];
    }
    sort(c.rbegin(), c.rend());

    ll mil = sum;
    ll rent = 0;

    auto it = lower_bound(psum.begin(), psum.end(), make_pair(mil, 0), [] (const pii &u,const pii &v) {
        return u.first < v.first;
    });
    it = prev(it);

    int idx = it - psum.begin();
    ll t2 = (idx + 1 == m ? 0LL : (mil - it->first) * b[idx + 1].first);
    ll ans = it->second + t2 + rent;

    for(int i = 0; i < min(n, r); i++) {
        mil -= a[i];
        rent += c[i];

        auto it = lower_bound(psum.begin(), psum.end(), make_pair(mil, 0), [] (const pii &u, const pii &v) {
            return u.first < v.first;
        });
        it = prev(it);

        idx = it - psum.begin();
        t2 = (idx + 1 == m ? 0LL : (mil - it->first) * b[idx + 1].first);
        ll tmp = it->second + t2 + rent;
        ans = max(ans, tmp);
    }
    cout << ans << '\n';
    return 0;
}