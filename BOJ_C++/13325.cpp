#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    ll n, ans = 0;
    cin >> n;

    ll k = (1 << (n + 1));
    vector<ll> a(k);

    for(int i = 2; i < k; i++) {
        cin >> a[i];
        ans += a[i];
    }

    function<ll(int)> go = [&] (int now) {
        if(now >= k) return 0LL;
        int next = now * 2;
        int next2 = now * 2 + 1;

        ll t1 = go(next);
        ll t2 = go(next2);

        if(t1 < t2) {
            ans += t2 - t1;
            return t2 + a[now];
        } else if(t1 > t2) {
            ans += t1 - t2;
            return t1 + a[now];
        } else return t1 + a[now]; 
    };

    go(1);

    cout << ans << '\n';

    return 0;
}