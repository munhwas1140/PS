#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;

    stack<pii> st;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        int now; cin >> now;
        while(!st.empty() && st.top().first <= now) {
            ans += i - st.top().second - 1;
            st.pop();
        }
        st.push({now, i});
    }

    while(!st.empty()) {
        if(st.top().second != n - 1) ans += n - st.top().second - 1;
        st.pop();
    }

    cout << ans << '\n';

    return 0;
}