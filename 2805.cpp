#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll m;
ll a[1000000];

ll check(ll mid) {
    ll ret = 0;
    for(int i = 0; i < n; i++) {
        ret += (a[i] - mid < 0 ? 0 : a[i] - mid);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    ll l = 0;
    ll r = 1e9;
    ll ans = 0;

    while(l <= r) {
        ll mid = (l + r) / 2;
        if(check(mid) >= m) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    } 
    
    cout << ans << '\n';

    return 0;
}