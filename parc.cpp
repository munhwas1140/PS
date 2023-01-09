#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    vector<pii> pv;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pv.push_back({a[i], i});
    }

    sort(pv.begin(), pv.end());
    int s, e;
    s = e = 0;
    
    int sum = 0;
    int ans = 1e9;
    set<int> st;
    while(s < n && e < n && s <= e) {
        while(e < n && sum + pv[e].first <= m) {
            sum += pv[e].first;
            st.insert(pv[e].second);
            e++;
        }

        int tmp = n - (e - s) + 1;
        if(e == n) {
            ans = min(ans, tmp);
            continue;
        }
        else if(st.count(e - s + 1)) tmp--;
        else {
            int val = a[e - s + 1];
            for(auto it = st.begin(); it != st.end(); it++) {
                if(a[*it] == val) {
                    tmp--;
                    break;
                }
            }
        }

        ans = min(ans, tmp);

        st.erase(pv[s].second);
        sum -= pv[s].first;
        s++;
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