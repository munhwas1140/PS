#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    ll n; cin >> n;
    if(n == 0 || n == 1) {
        cout << 2 << '\n';
        return ;
    }

    for(ll i = n; ;i++) {
        ll mx = sqrt(i);
        bool check = true;
        for(ll j = 2; j <= mx; j++) {
            if(i % j == 0) {
                check = false;
                break;
            }
        }
        if(check) {
            cout << i << '\n';
            return ;
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