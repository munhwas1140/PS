#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int main() {
    fastio;
    int n; cin >> n;
    vector<tuple<int,int,int>> a;
    for(int i = 0; i < n; i++) {
        int s, t;
        cin >> s >> t;
        a.emplace_back(s, i, t);
    }

    sort(a.begin(), a.end());
    int now = 0, ans = -1, it = 0;
    
    priority_queue<tuple<int,int,int>> pq;
    while(it < n) {
        if(pq.empty() && it < n) {
            auto [s, idx, t] = a[it++];
            pq.push({-idx, s, t});
        }
        auto [nidx, ns, nt] = pq.top();
        pq.pop();

        if(now < ns) now = ns + nt;
        else {
            ans = max(ans, now - ns);
            now = now + nt;
        }
        
        while(it < n && get<0>(a[it]) <= now ) {
            auto [cs, cidx, ct] = a[it];
            pq.push({-cidx, cs, ct});
            it++;
        }
    }

    cout << ans << '\n';

    return 0;
}