#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    string str, tar;
    cin >> str >> tar;
    int n = str.size(), m = tar.size();
    stack<char> st;
    for(int i = n - 1; i >= 0; i--) {
        st.push(str[i]);
        if(st.top() == tar[0]) {
            stack<char> tmpst;
            string tmp = "";
            for(int i = 0; !st.empty() && i < m; i++) {
                tmp += st.top();
                tmpst.push(st.top());
                st.pop();
            }

            if(tmp != tar) {
                while(!tmpst.empty()) {
                    st.push(tmpst.top()); tmpst.pop();
                }
            }
        }
    }
    string ans = "";
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }
    if(ans == "") cout << "FRULA" << '\n';
    else cout << ans << '\n';
    return 0;
}