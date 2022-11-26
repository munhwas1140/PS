#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    if(n == 2) {
        cout << 3 << ' ' << 1 << '\n';
        return ;
    }
    

    
    for(ll s = 1; ;s++) {

        for(ll e = s + n - 1; ;e++) {
            ll b = (e * (e + 1)) / 2;
            ll a = ((e - n + 1) * (e - n + 2)) / 2;
            ll x = b - a + s;
            ll sq = (e - s) * (e - s);
            if(x >= sq) {

            }

        }
    }

}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}