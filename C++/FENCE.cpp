#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int go(vector<int> &a, int s, int e) {
    if(s == e) return a[s];

    int m = (s + e) / 2;
    int ret = max(go(a, s, m), go(a, m + 1, e));    

    int l = m, r = m + 1;
    int hei = min(a[l], a[r]);
    ret = max(ret, 2 * hei);

    while(s < l || r < e) {
        if(r < e && (l == s || a[l - 1] < a[r + 1])) {
            r++;
            hei = min(hei, a[r]);
        } else {
            l--;
            hei = min(hei, a[l]);
        }

        ret = max(ret, hei * (r - l + 1));
    }

    return ret;
}
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << go(a, 0, n - 1) << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }

    return 0;
}