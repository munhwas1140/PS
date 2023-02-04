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
        int s, e, idx;
        cin >> idx >> s >> e;
        a.push_back({s, 1, idx});
        a.push_back({e, -1, idx});
    }

    vector<int> ans(n + 1);
    sort(a.begin(), a.end());
    
    int mx = 0, now = 0;
    for(auto &[d, val, idx] : a) {
        if(val == 1) now++;
        else now--;
        mx = max(mx, now);
    }

    priority_queue<int> pq;
    for(int i = 1; i <= mx; i++) pq.push(i);

    for(auto &[d, val, idx] : a) {
        if(val == 1) {
            ans[idx] = pq.top();
            pq.pop();
        } else {
            pq.push(ans[idx]);
        }
    }

    cout << mx << '\n';
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }
    cout << '\n';

    return 0;
}