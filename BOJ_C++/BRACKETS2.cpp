#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int ctoi(char x) {
    switch(x) {
        case '(': return 1;
        case '{': return 2;
        case '[': return 3;
        case ')': return 4;
        case '}': return 8;
        case ']': return 12;
    }
    return -1;
}
bool solve() {
    string str; cin >> str;
    int n = str.size();
    stack<int> st;

    for(int i = 0; i < n; i++) {
        int now = ctoi(str[i]);
        if(now >= 4) {
            if(st.empty() || st.top() != now / 4) return false;
            st.pop();
        } else st.push(now);
    }
    return st.empty();
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
    return 0;
}