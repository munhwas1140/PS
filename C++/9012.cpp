#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    while(tc--) {
        string str;
        cin >> str;
        stack<char> st;
        bool f = true;
        for(char &c : str) {
            if(c == '(') {
                st.push(c);
            } else {
                if(st.empty()) {
                    f = false;
                    break;
                } else {
                    if(st.top() == '(') st.pop();
                    else {
                        f = false;
                        break;
                    }
                }
            }
        }

        if(!st.empty()) f = false;
        if(f) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }     
      
    return 0;
}