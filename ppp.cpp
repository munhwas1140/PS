#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    ll tmp = 0;
    ll check = 1e18;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        check = min(check, a[i]);
    }
    if(a[0] == check) {
        cout << "Bob" << '\n';
    } else {
        cout << "Alice" << '\n';
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