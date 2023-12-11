#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    stack<int> st;
    int idx = 0;
    vector<char> ans;

    bool ok = true;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        while(idx < tmp) {
            ans.push_back('+');
            st.push(++idx);
        }

        while(!st.empty() && tmp < st.top()) {
            st.pop();
            ans.push_back('-');
            st.pop();
        }

        if(st.empty()) {
            ok = false;
            break;
        } else {
            st.pop();
            ans.push_back('-');
        }
    }

    if(ok) {
        for(auto &x : ans) cout << x << '\n';
    } else {
        cout << "NO" << '\n';
    }

    return 0;
}