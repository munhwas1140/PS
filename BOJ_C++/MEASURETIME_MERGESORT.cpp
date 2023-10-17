#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
ll mergesort(vector<int> &a, int s, int e) {
    if(s == e) return 0LL;
    
    int m = (s + e) / 2;
    ll ret = mergesort(a, s, m) + mergesort(a, m + 1, e);
    
    vector<int> tmp(e - s + 1);
    int i, l, r;
    i = 0;
    l = s;
    r = m + 1;
    while(l <= m || r <= e) {
        if(l <= m && (r > e || a[l] <= a[r])) {
            tmp[i++] = a[l++];
        } else {
            ret += m - l + 1;
            tmp[i++] = a[r++];
        }
    }

    for(int i = 0; i < e - s + 1; i++) {
        a[s + i] = tmp[i];
    }
    return ret;
}
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    cout << mergesort(a, 0, n - 1) << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}