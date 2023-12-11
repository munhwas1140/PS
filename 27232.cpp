#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; ll k;
    cin >> n >> k;
    vector<int> a(n);
    vector<ll> pos(n + 1);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    if(k == 1) {
        cout << 0 << '\n'; return 0;
    } else if(k == 2) {
        cout << 1 << '\n'; return 0;
    }
    
    priority_queue<int> q;
    set<int> st;
    for(int i = 0; i < k; i++) {
        q.push(a[i]);
        st.insert(a[i]);
    }
    
    ll ans = 1e18, ret = 0;
    while(q.size() != 1) {
        int now1 = q.top(); q.pop();
        int now2 = q.top(); q.pop();
        ret += abs(pos[now1] - pos[now2]);
        q.push(now2);
    }

    ans = min(ans, ret);
    for(ll i = k; i < n; i++) {
        int past = a[i - k];
        st.erase(past);
        auto it1 = st.lower_bound(past);
        int t1 = -1, t2 = -1;
        if(it1 == st.end()) {
            it1--;
            ret -= pos[*it1] - (i - k);
        } else if(it1 == st.begin()) {
            ret -= pos[*it1] - (i - k);
        } else {
            auto it2 = st.lower_bound(past);
            it2--;
            ret += abs(pos[*it1] - pos[*it2]);
            ret -= pos[*it1] + pos[*it2] - 2 * (i - k);
        }
    

        it1 = st.lower_bound(a[i]);

        if(it1 == st.end()) {
            it1--;
            ret += i - pos[*it1];
        } else if(it1 == st.begin()) {
            ret += i - pos[*it1];
        } else {
            auto it2 = st.lower_bound(a[i]);
            it2--;
            ret -= abs(pos[*it1] - pos[*it2]);
            ret += (2 * i) - pos[*it1] - pos[*it2];
        }

        st.insert(a[i]);
        ans = min(ans, ret);
    }

    cout << ans << '\n';
    return 0;
}