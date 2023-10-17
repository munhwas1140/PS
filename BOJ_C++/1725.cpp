#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[100000];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    stack<pair<ll, int>> st;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        while(!st.empty() && st.top().first > a[i]) {
            auto now = st.top();
            st.pop();
            if(st.empty()) {
                ans = max(ans, now.first * i);
            } else {
                ans = max(ans, now.first * (i - st.top().second));
            }
        }
        st.push({a[i], i + 1});
    }
    
    while(!st.empty()) {
        auto now = st.top();
        st.pop();
        if(st.empty()) {
            ans = max(ans, now.first * n);
        } else {
            ans = max(ans, now.first * (n - st.top().second));
        }
    }
    cout << ans << '\n';
    return 0;
}