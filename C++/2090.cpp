#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<ll> a(n);
    for(auto &x : a) cin >> x;

    ll GCD = a[0];
    for(int i = 1; i < n; i++) {
        GCD = gcd(GCD, a[i]);
    }

    ll lcm = a[0];
    for(int i = 1; i < n; i++) {
        lcm *= a[i];
        lcm /= GCD;
    }
    
    ll bunza = 0;
    for(int i = 0; i < n; i++) {
        bunza += lcm / a[i];
    }

    ll GCD2 = gcd(lcm, bunza);
    lcm /= GCD2;
    bunza /= GCD2;

    cout << lcm << '/' << bunza << '\n';
    
    return 0;
}