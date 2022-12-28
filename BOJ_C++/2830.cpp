#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    ll n; cin >> n;
    ll cnt[20] = {0,};
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        for(int j = 0; j < 20; j++) {
            cnt[j] += tmp % 2;
            tmp /= 2;
        }
    }
    ll ans = 0;
    for(int i = 0; i < 20; i++) {
        ans += (1 << i) * (n - cnt[i]) * (cnt[i]);
    }
    cout << ans << '\n';

    return 0;
}