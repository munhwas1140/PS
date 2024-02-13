#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = 0;
    for(ll i = 0; i < n; i++) {
        ll it = i;
        while(it < n && a[it] < a[it + 1]) it++;
        ll cnt = it + 1 - i;
        ans += (cnt * (cnt + 1)) / 2;
        i = it;
    }
    cout << ans << '\n';

    return 0;
}