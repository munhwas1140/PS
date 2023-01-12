#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    ll a, b;
    cin >> a >> b;
    if(a < b || (a & b) != b) cout << -1 << '\n';
    else if(a == b) cout << a << '\n';
    else {
        vector<int> aa(64), bb(64);
        for(int i = 0; i < 64; i++) {
            aa[i] = !!(a & (1LL << i));
        }
        for(int i = 0; i < 64; i++) {
            bb[i] = !!(b & (1LL << i));
        }
        
        int idx = -1;
        for(int i = 63; i >= 0; i--) {
            if(aa[i] && !bb[i]) {
                if(idx == -1) {
                    idx = i;
                };
            } else if(aa[i] && bb[i] && idx != -1) {
                cout << -1 << '\n';
                return ;
            }
        }
        
        if(aa[idx + 1]) {
            cout << -1 << '\n';
            return ;
        }
        
        a |= (1LL << (idx + 1));
        a &= ~((1LL << (idx + 1)) - 1);
        cout << a << '\n';
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