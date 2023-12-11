#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int m, k, a, b;
    cin >> m >> k >> a >> b;
    
    int ans = m;

    int km = max(0, m - min(m / k, b) * k);
    ans = min(ans, km / k + km % k);
    km = max(0, km - a);
    ans = min(ans, km / k + km % k);

    if(a >= m % k) {
        a -= m % k;
        m -= m % k;
        km = max(0, m - min(m / k, b) * k);
        ans = min(ans, max(0, (km - (a / k) * k)) / k);
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