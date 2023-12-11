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
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    int e, now;
    cin >> e >> now;
    if(now >= e) {
        cout << 0 << '\n';
        return 0;
    }

    sort(a.begin(), a.end());
    
    int it = 0;
    int ans = 0;
    priority_queue<int> pq;
    while(it < n) {
        while(it < n && a[it].first <= now) {
            pq.push(a[it].second);
            it++;
        }
        if(pq.empty()) break;

        now += pq.top();
        pq.pop();
        ans++;

        if(now >= e) break;
    }

    if(now >= e) cout << ans << '\n';
    else cout << -1 << '\n';

    return 0;
}