#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
int n;
ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}
bool check(ll a, ll b) {
    ll GCD = gcd(a, b);
    a /= GCD;
    b /= GCD;
    if(sqrt(a) != (ll)sqrt(a)) return false;
    if(sqrt(b) != (ll)sqrt(b)) return false;
    return true;
}
int main() {
    fastio;
    cin >> n;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(),b.end());
    for(int i = 0; i < n; i++) {
        if(!check(b[i], a[i])) return !(cout << "NO" << '\n');
    }
    return !(cout << "YES" << '\n');
}