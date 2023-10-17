#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    
    int cnt= 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll now = 0;
    int it = 0;

    while(it < n) {
        if(a[it] > 0) {
            if(now < 0) {
                if(now + a[it] > 0) {
                    now += a[it];
                } else {
                    cnt--;
                    now = a[it];
                }
            } else if(now  0) {
                cnt++;
                now = a[it];
            } else {
                now = a[it];
            }
        } else if(a[it] < 0) {
            if(now < 0) {
                now += a[it];
            } else if(now > 0) {
                if(now + a[it] <= 0) {
                    cnt++;
                    now = a[it];
                } else {
                    now += a[it];
                }
            } else {
                now = a[it];
            }
        }
        it++;
    }

    if(now > 0) cnt++;
    else if(now < 0) cnt--;
    
    if(cnt >= 1) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}


// (5 2 -1 )-5

// 5 2 -1 -5
// + + - (5, 2, (-1, -5)), (5, (2, -1), -5)
// +
// +1 

// 6 1 -2 -5
// + + - 6, 1, (-2, -5)
// 6 -2 1 -5


// 6 -1 -4