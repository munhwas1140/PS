#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;

int main() {
    fastio;
    cin >> n;
    int l, r;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        if(i == 0) {
            l = tmp;
        } else if(i == 1) {
            r = tmp;
        } else {
            if(l <= r) {
                l += tmp;
            } else {
                r += tmp;
            }
        }
    }
    
    int ans = 0;
    int now = abs(l - r);
    cout << now << '\n';
    int t[] = {1,2,5,10,20,50,100};
    for(int i = 6; i >= 0; i--) {
        if(now / t[i]) {
            ans += now / t[i];
            now %= t[i];
        }
    }
    cout << ans << '\n';
    return 0;
}