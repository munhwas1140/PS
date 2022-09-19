#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;

int main() {
    fastio;
    int tc;
    cin >> tc;
    while(tc--) {
        int n;
        ll x, y;
        cin >> n >> x >> y;
        string t1, t2;
        cin >> t1 >> t2;
        vector<int> diff(n);
        int diffnum = 0;
        for(int i = 0; i < n; i++) {
            diff[i] = (t1[i] != t2[i]);
            diffnum += diff[i];
        }
        if(diffnum % 2) {
            cout << -1 << '\n';
            continue;
        }
        // for(int i = 0; i < n ; i++) {
        //     cout << diff[i] << ' ' ;
        // }
        // cout << '\n';
        // cout << diffnum << '\n';
        // cout << '\n';
        ll ans = 0;
        if(x > y * 2 && n >= 4) {
            if(diffnum > 2) {
                ans += y * 2;
            } else {
                if(diff[0] && diff[1] || diff[1] && diff[2] || diff[2] && diff[3]) {
                    ans += y * 2;
                } else ans = y * (diffnum / 2);
            }
        } else if(x > y * 2 && n == 3) {
            if(diff[0] && diff[2]) ans = y;
            else if(diff[1]) ans = x;
        } else {
            for(int i = 0; i < n - 1; i++) {
                if(diff[i] && diff[i+1]) {
                    ans += x;
                    diff[i] = 0; diff[i+1] = 0;
                    diffnum -= 2;
                }
            }
            ans += y * (diffnum / 2);
        }
        cout << ans << '\n';
    }
    return 0;
}