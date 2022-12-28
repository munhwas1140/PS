#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    ll n; cin >> n;
    vector<ll> pxor(n + 1);
    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pxor[i] = pxor[i - 1] ^ a[i];
    }

    ll cnt[31] = {0,};

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 31; j++) {
            cnt[j] += pxor[i] % 2;
            pxor[i] /= 2;
        }
    }

    ll ans = 0;
    for(int i = 0; i < 31; i++) {
        ans += (1LL << i) * (cnt[i]) * (n + 1 - cnt[i]);
    }
    cout << ans << '\n';

    return 0;
}