#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n + 1);
    vector<ll> psum(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    for(int i = 1; i <= n; i++) {
        psum[i] = psum[i - 1] + a[i];
    }
    
    ll ans = 0;
    for(ll i = n; i >= 1; i--) {
        if(x - psum[i] < 0) continue;
        ans++;
        ll tmp = (x - psum[i]) / i;
        ans += tmp;
    }
    cout << ans << '\n';
    return ;
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}