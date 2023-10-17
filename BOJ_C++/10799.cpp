#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    string str; cin >> str;
    int n = str.size();

    ll ans = 0;
    stack<char> st;
    for(int i = 0; i < n; i++) {
        int c = str[i];
        if(c == '(') {
            st.push(c);
        } else if(c == ')') {
            st.pop();
            if(i > 0 && str[i - 1] == '(') {
                ans += st.size();
            } else {
                ans += 1;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}