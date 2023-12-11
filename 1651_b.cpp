#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
vector<ll> a;
void solve() {
    int n; cin >> n;
    if(n > a.size()) cout << "NO" << '\n';
    else {
        cout << "YES" << '\n';
        for(int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
}
int main() {
    a.push_back(1);
    ll now = 2;
    while(true) {
        if(a.back() + now > 1000000000) {
            break;
        }
        a.push_back(a.back() + now);
        now *= 3;
    }
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}