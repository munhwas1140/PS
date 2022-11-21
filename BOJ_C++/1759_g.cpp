#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    vector<int> a(n / 2), ans(n);
    vector<bool> check(n + 1);

    for(int i = 0; i < n / 2; i++) {
        cin >> a[i];
        check[a[i]] = true;
        ans[2 * i + 1] = a[i];
    }

    set<int> st;
    for(int i = 1; i <= n; i++) {
        if(!check[i]) st.insert(i);
    }
    
    if(st.size() != n / 2) {
        cout << -1 << '\n';
        return ;
    }

    for(int i = (n / 2) - 1; i >= 0; i--) {
        auto k = st.upper_bound(ans[i * 2 + 1]);
        if(k == st.begin()) {
            cout << -1 << '\n';
            return ;
        }
        k--;
        if(*k < ans[i * 2 + 1]) {
            ans[2 * i] = *k;
            st.erase(k);
        } else {
            cout << -1 << '\n';
            return ;
        }
    }
    for(int i = 0; i < n; i++) {
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