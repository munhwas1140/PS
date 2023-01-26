#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    map<int,int> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    priority_queue<pii> pq;

    for(auto it = mp.begin(); it != mp.end(); it++) {
        pq.push({it->second, it->first});
    }

    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    int ans = 0;
    for(int i = m - 1; i >= 0; i--) {
        auto p = pq.top();
        pq.pop();
        ans += min(p.first, b[i]);
        p.first-= min(p.first, b[i]);
        if(p.second != 0) {
            pq.push(p);
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