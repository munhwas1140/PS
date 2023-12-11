#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
int main() {
    fastio;
    cin >> n;
    vector<ll> a(n);
    vector<ll> psum(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++) {
        if(i == 0) psum[i] = a[i];
        else psum[i] = psum[i - 1] + a[i];
    }

    ll ans = 0;
    for(int i = 0; i < n - 1; i++) {
        ans += a[i] * (psum[n - 1] - psum[i]);
    }
    cout << ans << '\n';
    

    return 0;
}