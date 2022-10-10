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
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        vector<int> cnt(n);
        int i1 = 0, i2 = 0;
        while(true) {
            if(i1 >= n) break;
            if(i2 >= n) {
                cnt[i1] = i2 - i1;
                i1++;
            } else if(a[i2] > i2 - i1) {
                i2++;
            } else {
                cnt[i1] = i2 - i1;
                i1++;
            }
        }
        ll ans = 0;
        for(int i = 0; i < n; i++) {
            ans += (ll)cnt[i];
        }
        cout << ans << '\n';

    }

    return 0;
}