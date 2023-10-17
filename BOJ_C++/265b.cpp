#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;

int main() {
    fastio;
    ll n, m, t;
    cin >> n >> m >> t;
    vector<ll> a(n - 1);
    for(int i = 0; i < n - 1; i++) {
        cin >> a[i];
        a[i] = -a[i];
    }

    for(int i = 0; i < m; i++) {
        ll t1, t2;
        cin >> t1 >> t2;
        t1--;
        a[t1] += t2;
    }

    bool ok = true;
    for(int i = 0; i < n - 1; i++) {
        t += a[i];
        if(t <= 0) ok = false;
    }
    if(ok) cout << "Yes" << '\n';
    else cout << "No" << '\n';

    return 0;
}