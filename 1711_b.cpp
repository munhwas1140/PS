#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), x(m), y(m), deg(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
        x[i]--; y[i]--;
        deg[x[i]]++;
        deg[y[i]]++;
    }

    int ans = 1e9;
    if(m % 2 == 0) {
        ans = 0;
    } else {
        for(int i = 0; i < n; i++) {
            if(deg[i] % 2 == 1) ans = min(ans, a[i]);
        }
        for(int i = 0; i < m; i++) {
            if(deg[x[i]] % 2 == 0 && deg[y[i]] % 2 == 0) {
                ans = min(ans, a[x[i]] + a[y[i]]);
            }
        }
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