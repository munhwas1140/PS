#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    ll n, c, d;
    cin >> n >> c >> d;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());

    int s = 0;
    int e = d + 1;
    int ans = -1;
    while(s <= e) {
        int m = (s + e) / 2;
    
        ll sum = 0;
        for(int i = 0; i < d; i++) {
            int idx = i % (m + 1);
            if(idx < n) sum += a[idx];
        }

        if(sum >= c) {
            ans = m;
            s = m + 1;
        } else {
            e = m - 1;
        }
    }
    if(ans == -1) {
        cout << "Impossible" << '\n';
    } else {
        if(ans == d + 1) {
            cout << "Infinity" << '\n';
        } else {
            cout << ans << '\n';
        }
    }
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}