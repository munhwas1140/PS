#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, p;
void solve() {
    cin >> n >> p;
    vector<int> a(n);
    vector<int> b(n + 1);
    set<int> st;

    int last;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[i + 1] = a[i];
        st.insert(a[i]);
        if(i == n - 1) last = a[i];
    }
    b[n - 1]++;
    for(int i = n - 1; i >= 1; i--) {
        if(b[i] == p) {
            b[i] = 0;
            b[i - 1]++;
        }
    }

    sort(a.begin(), a.end());
    int ans = 0;
    if(a[0] != 0) {
        for(int i = 0; i <= n; i++) {
            st.insert(b[i]);
        }
        st.insert(0);

        ans += p - last;

        for(int i = last - 1; i > 0; i--) {
            if(st.count(i) == 0) {
                ans += i;
                break;
            }
        }
    } else {
        int idx = -1;
        for(int i = last - 1; i > 0; i--) {
            if(st.count(i) == 0) {
                idx = i;
                break;
            }
        }

        if(idx == -1) {

            for(int i = p - 1; i >= last + 1; i--) {
                if(st.count(i) == 0) {
                    idx = i;
                    break;
                }
            }
            if(idx != -1) {
                ans += idx - last;
            }

        } else {
            ans += p - last;

            for(int i = 0; i <= n; i++) {
                st.insert(b[i]);
            }
            st.insert(0);

            int idx = -1;
            for(int i = last - 1; i > 0; i--) {
                if(st.count(i) == 0) {
                    idx = i;
                    break;
                }
            }
            if(idx != -1) ans += idx;
        }
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