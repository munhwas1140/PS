#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    ll g = gcd(a, b);
    return a * b / g;
}
void solve() {
    int n; cin >> n;
    vector<ll> a(n + 2, 1LL);
    vector<ll> b(n + 2, 1LL);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n + 1; i++) {
        b[i] = lcm(a[i], a[i - 1]);
    }

    for(int i = 1; i <= n; i++) {
        if(gcd(b[i], b[i + 1]) != a[i]) {
            cout << "NO" << '\n';
            return ;
        }
    } 
    cout << "YES" << '\n';
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