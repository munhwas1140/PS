#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll mod = 998244353;
ll n, m;
ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}
ll go(int now, ll tar) {
    if(now == tar + 1) {
        return 1;
    }

    ll ret = 0;
    for(ll i = 1; i <= m; i++) {
        if(gcd(now, i) == 1) {
            ret += go(now + 1, tar);
        } else {
            ret += pow(m, tar - now);
        }
    }
    return ret;
}
void solve() {
    cin >> n >> m;
    ll ans = 0;
    cout << ans << '\n';
}
int main() {
    
    fastio;
    solve();
    return 0;
}