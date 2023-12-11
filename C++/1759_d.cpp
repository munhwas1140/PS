#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    ll n, m;
    cin >> n >> m;
    
    ll tmp = n;
    int t, f;
    t = f = 0;
    while(tmp % 2 == 0) {
        tmp /= 2;
        t++;
    }

    while(tmp % 5 == 0) {
        tmp /= 5;
        f++;
    }

    ll ans = 1;
    if(t > f) {
        for(int i = 0; i < t - f; i++) {
            if(ans * 5 > m) break;
            ans *= 5;
        }
    } else if(f > t) {
        for(int i = 0; i < f - t; i++) {
            if(ans * 2 > m) break;
            ans *= 2;
        }
    }


    while(ans * 10 <= m) {
        ans *= 10;
    }
    
    for(ll i = 1; i <= 10; i++) {
        if(ans * i > m) {
            ans *= (i - 1);
            break;
        }
    }
    cout << n * ans << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}