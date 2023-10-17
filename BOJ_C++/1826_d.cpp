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

    priority_queue<pii> r;
    priority_queue<int> l;
    l.push(a[0] + 1);
    for(int i = 0; i < n; i++) {
        r.push({a[n - i - 1] - (n - i), n - i - 1});
    }

    int ans = -1;
    for(int i = 1; i < n - 1; i++) {
        while(r.top().second <= i) r.pop();
        ans = max(ans, a[i] + l.top() + r.top().first);
        l.push(a[i] + i + 1);
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