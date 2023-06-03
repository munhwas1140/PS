#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
string tmp = "";
int cnt = 1;
bool check() {
    stack<char> st;
    for(char c : tmp) {
        if(c == '(') st.push(c);
        else {
            if(st.empty()) return true;
            else {
                if(st.top() == '(') st.pop();
            }
        }
    }
    return !st.empty();
}
void go(int now) {
    if(now == 4) {
        if(check()) {
            cout << (cnt++) << ' ' << tmp << '\n';
        }
        return ;
    }
    tmp += "(";
    go(now + 1);
    tmp.pop_back();
    tmp += ")";
    go(now + 1);
    tmp.pop_back();
}
int main() {
    fastio;
    go(0);
    return 0;
}