#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
struct asdf {
    int s, e, idx;
};
void solve() {
    int n; cin >> n;
    vector<asdf> a(n);
    vector<int> ans(n + 1);
    for(int i = 1; i <= n; i++) {
        int tmp; cin >> tmp;
        int s = (i / (tmp + 1)) + 1;
        int e = (tmp == 0 ? n : (i / tmp));
        a[i - 1] = {s, e, i};
    }
    sort(a.begin(), a.end(), [] (const asdf &u, const asdf &v) {
        if(u.e == v.e) {
            if(u.s == v.s) {
                return u.idx < v.idx;
            }
            return u.s < v.s;
        }
        return u.e < v.e;
        
    });
    
    set<int> st;
    vector<bool> check(n + 1);
    for(auto [s, e, idx] : a) {
        // cout << s << ' ' << e << ' ' << idx << '\n';
        if(check[s]) {
            set<int>::iterator it;
            while(true) {
                it = st.lower_bound(s);
                s = (*it) + 1;
                if(check[s]) {
                    st.erase(it);
                } else break;
            }
            check[s] = true;
            ans[idx] = s;
            st.insert(s);
            st.erase(it);
        } else {
            check[s] = true;
            ans[idx] = s;
            st.insert(s);
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}