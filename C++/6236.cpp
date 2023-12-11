#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[100000];
int n, m;

bool check(ll mid) {
    int cnt = 1;
    ll sum = mid;
    
    for(int i = 0; i < n; i++) {
        if(sum - a[i] < 0) {
            cnt += 1;
            sum = mid - a[i];
        } else sum -= a[i];
    }
    return cnt <= m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    ll l = -1, r = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        l = max(l, a[i]);
        r += a[i];
    }        
     
    ll ans;
    while(l <= r) {
        ll mid = (l + r) / 2;
        if(check(mid)) {
            r = mid - 1;
            ans = mid;
        } else l = mid + 1;
    }

    cout << ans << '\n'; 

    return 0;
}