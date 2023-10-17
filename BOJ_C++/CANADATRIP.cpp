#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n; ll k;
struct asdf {
    int l,m,g;
};
bool check(vector<asdf> &a, int m) {
    ll cnt = 0;
    for(int i = 0; i < n; i++) {
        int e = a[i].l;
        int s = a[i].m;
        int gap = a[i].g;
        if(m < s) continue;
        cnt += ll(((min(e, m) - s) / gap) + 1);
    }
    return cnt >= k;
}
void solve() {
    cin >> n >> k;
    vector<asdf> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].l >> a[i].m >> a[i].g;
        a[i].m = a[i].l - a[i].m;
    }
    
    int l = 0, r = 8030000;
    int ans = -1;
    while(l <= r) {
        int m = (l + r) / 2;
        if(check(a, m)) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << ans << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}