#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string str;
    cin >> str;
    stack<char> st;
    for(char c : str) {
        if(c == '(') {
            st.push(c);
        } else if(c == ')') {
            while(!st.empty() && st.top() != '(') {
                cout << st.top();
                st.pop();
            }
            st.pop();
        } else if(c == '*' || c == '/') {
            while(!st.empty() && (st.top() == '*' || st.top() == '/')) {
                cout << st.top();
                st.pop();
            }
            st.push(c); 
        } else if(c == '+' || c == '-') {
            while(!st.empty() && st.top() != '(') {
                cout << st.top();
                st.pop();
            }
            st.push(c);
        } else {
            cout << c;
        }
    }

    while(!st.empty()) {
        cout << st.top();
        st.pop();
    }
    return 0;
}