#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
int main() {
    fastio;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    
    ll ans = 1e18;
    for(int i = 1; i < (1 << n); i++) {
        ll s, b;
        s = 1;
        b = 0;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                s *= a[j].first;
                b += a[j].second;
            }
        }
        ans = min(ans, abs(s - b));
    }
    cout << ans << '\n';
    return 0;
}