#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    if(a[1] == a[n]) {
        cout << n / 2 << '\n';
        return ;
    }
    int s = 1;
    ll ans = 0;
    while(s <= n) {
        while(s + 1 <= n && a[s] == a[s + 1]) s++;
        ans = max(ans, (ll)s * (n - s));
        s++;
    }
    cout << ans << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}