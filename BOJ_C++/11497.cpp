#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> ans(n);
    int l, r;
    l = 0, r = n - 1;
    for(int i = 0; i < n; i++) {
        if(i % 2) ans[l++] = a[i];
        else ans[r--] = a[i];
    }

    int ret = 0;
    for(int i = 0; i < n - 1; i++) {
        ret = max(ret, abs(ans[i] - ans[i + 1]));
    }
    ret = max(ret, abs(ans[0] - ans[n - 1]));
    cout << ret << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}