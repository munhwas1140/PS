#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    int maxv = -1, minv = 1e9;
    vector<int> a(n);
    int t1, t2;
    t1 = t2 = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        maxv = max(maxv, a[i]);
        minv = min(minv, a[i]);
    }
    
    for(int i = 0; i < n; i++) {
        if(a[i] == maxv) t1++;
        if(a[i] == minv) t2++;
    }

    if(minv != maxv) {
        cout << t1 * t2 * 2 << '\n';
    } else {
        cout << n * (n - 1) << '\n';
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