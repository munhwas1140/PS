#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<pair<ll,ll>> a;
    for(int i = 0; i < n; i++) {
        ll x, r;
        cin >> x >> r;
        a.push_back({x - r, x + r});
    }
    sort(a.begin(), a.end(), [](auto &u, auto &v) {
        if(u.first == v.first) return u.second > v.second;
        return u.first < v.first;
    });
    stack<pair<ll, ll>> st;
    ll ans = n + 1;
    for(int i = 0; i < n; i++) {
        while(!st.empty() && st.top().second < a[i].first) st.pop();
        if(st.empty() || st.top().first == a[i].first) {
            st.push(a[i]);
        } else {
            if(st.top().second >= a[i].second) {
                st.pop();
                st.push(a[i]);
                continue;
            }
            
            if(st.top().second == a[i].first) {
                st.pop();
                if(st.empty()) {
                    st.push(a[i]);
                    continue;
                }
                if(st.top().second == a[i].second) {
                    ans++;
                    st.pop();
                } else {
                    st.push(a[i]);
                }
            }
            while(!st.empty() && st.top().second < a[i].first) st.pop();
        }
    }
    cout << ans << '\n';

    return 0;
}