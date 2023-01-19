#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        ll ans = 0, now = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(a[i] > now) now = a[i];
            ans += now - a[i];
        }
        cout << ans << '\n';
    }
    return 0;
}