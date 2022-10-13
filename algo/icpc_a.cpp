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
        int l, r;
        l = r = 0;
        for(int i = 0; i < n; i++) {
            int tmp; cin >> tmp;
            if(i == 0) l = tmp;
            else if(i == 1) r = tmp;
            else {
                if(l == r) {
                    l += tmp;
                } else if(l > r) {
                    r += tmp;
                } else l += tmp;
            }
        }

        int t[] = {1,2,5,10,20,50,100};
        int tmp = abs(l - r);
        int ans = 0;
        for(int i = 6; i >= 0; i--) {
            ans += tmp / t[i];
            tmp %= t[i];
        }
        cout << ans << '\n';
    }
    return 0;
}