#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ll tmp; cin >> tmp;
        pq.push(tmp);
    }

    while(pq.size() != 1) {
        ll t1 = pq.top();
        pq.pop();
        ll t2 = pq.top();
        pq.pop();
        ans += t1 + t2;
        pq.push(t1 + t2);
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