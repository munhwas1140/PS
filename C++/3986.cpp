#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    int ans = 0;
    while(tc--) {
        string str;
        cin >> str;
        stack<char> st;
        bool f = true;
        for(char &c : str) {
            if(st.empty()) {
                st.push(c);
            } else {
                if(c == 'A') {
                    if(st.top() == 'A') {
                        st.pop();
                    } else {
                        st.push(c);
                    }
                } else if(c == 'B') {
                    if(st.top() == 'B') {
                        st.pop();
                    } else {
                        st.push(c);
                    }
                }
            }
        }
        if(!st.empty()) f = false;
        ans += f;     
    }     
    cout << ans << '\n';
    return 0;
}