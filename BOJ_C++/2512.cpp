#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll M, a[10000];
int N;
ll check(ll mid) {
    ll ret = 0;
    for(int i = 0; i < N; i++) {
        ret += (a[i] > mid ? mid : a[i]);
    } 
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N;
    ll r = -1;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        r = max(r, a[i]);
    }
    cin >> M;

    ll l = 1;
    ll ans;
    while(l <= r) {
        ll mid = (l + r) / 2;
        if(check(mid) <= M) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    cout << ans << '\n';

    return 0;
}