#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int c, n;
    cin >> c >> n;
    vector<int> dk(c);
    vector<pii> so(n);
    for(int i = 0; i < c; i++) {
        cin >> dk[i];
    }

    for(auto &[s, e] : so) {
        cin >> s >> e;
    }

    sort(dk.begin(), dk.end());
    sort(so.begin(), so.end());
    priority_queue<pii> pq;

    int ans = 0, it = 0;
    for(int i = 0; i < c; i++) {
        while(it < n && so[it].first <= dk[i]) {
            pq.push({-so[it].second, so[it].first});
            it++;
        }

        while(!pq.empty() && -pq.top().first < dk[i]) pq.pop();
        if(!pq.empty()) {
            pq.pop();
            ans++;
        }
        
    }
    cout << ans << '\n';

    return 0;
}