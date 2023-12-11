#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<pii> a(n);
    for(auto &[d, v] : a) {
        cin >> d >> v;
    }

    sort(a.rbegin(), a.rend());

    int idx = 0;
    int ans = 0;
    priority_queue<int> pq;
    for(int i = n; i >= 1; i--) {
        while(idx < n && a[idx].first >= i) {
            pq.push(a[idx++].second);
        }

        if(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << '\n';
    return 0;
}