#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[10000];
int n, k;
int check(ll m) {
    int ret = 0;
    for(int i = 0; i < n; i++) {
        ret += a[i] / m;
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }    

    ll l = 0;
    ll r = 3e9;
    ll ans = 0;

    while(l <= r) {
        ll m = (l + r) / 2;
        if(check(m) >= k) {
            ans = m;
            l = m + 1;
        } else r = m - 1;
    } 
    
    cout << ans << '\n';

    return 0;
}  