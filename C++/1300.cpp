#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, k;

ll check(ll mid) {
    if(mid <= 0) return 0;
    ll ret = 0;

    for(int i = 1; i <= n; i++) {
        if(i > mid) break;
        if(mid >= i * n) {
            ret += n;
        } else {
            ret += mid / i;
        }
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;

    ll l = 1, r = n * n;
    ll ans;    
    while(l <= r) {
        ll m = (l + r) / 2;
        if(check(m) >= k) {
            ans = m;
            r = m - 1;
        } else l = m + 1;
    }
    cout << ans << '\n';
  
    return 0;
}