#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
ll MOD = 998244353;
ll a[300001];
ll go(int s, int e) {
    if(s + 1 == e) {
        return 1LL;
    } else if(s == e) return 0LL;

    int it = -1;
    ll mn = 1e10;
    for(int i = s; i < e; i++) {
        if(a[i] < mn) {
            it = i;
            mn = a[i];
        }
    }

    return (go(s, it) * go(it + 1, e) + go(s, it) + go(it + 1, e) + 1) % MOD;
}
void solve() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << go(0, n) << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}