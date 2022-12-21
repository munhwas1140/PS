#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    string str;
    while(getline(cin, str)) {
        if(str == ".") break;
        stack<char> st;
        auto check = [&]() {
            for(auto &c : str) {
                if(c == '(' || c == '[') {
                    st.push(c);
                } else if(c == ')') {
                    if(st.empty() || st.top() != '(') return false;
                    st.pop();
                } else if(c == ']') {
                    if(st.empty() || st.top() != '[') return false;
                    st.pop();
                }
            }
            return (int)st.size() == 0;
        };
        if(check()) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }
    return 0;
}