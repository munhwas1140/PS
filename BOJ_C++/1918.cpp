#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int conv[128];

void init() {
    conv['('] = conv[')'] = 1;
    conv['+'] = conv['-'] = 2;
    conv['*'] = conv['/'] = 3;
}

int main() {
    fastio;
    init();
    string str, ans;
    cin >> str;
    str = "(" + str + ")";
    stack<char> st;
    for(auto &c : str) {
        if(isalpha(c)) {
            ans.push_back(c);
        } else if(c == '(') {
            st.push(c);
        } else if(c == ')') {
            while(!st.empty() && st.top() != '(') {
                ans.push_back(st.top()); st.pop();
            }
            st.pop();
        } else {
            while(!st.empty() && conv[c] <= conv[st.top()]) {
                ans.push_back(st.top()); st.pop();
            }
            st.push(c);
        }
    }
    cout << ans << '\n';
    return 0;
}