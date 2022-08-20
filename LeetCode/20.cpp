#include <bits/stdc++.h>
using namespace std;

// Valid Parentheses

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char x : s) {
            if(x == '(' || x == '[' || x == '{') {
                st.push(x);
            } else if(x == ')') {
                if(!st.empty() && st.top() == '(') {
                    st.pop();
                } else {
                    return false;
                }
            }  else if(x == '}') {
                if(!st.empty() && st.top() == '{') {
                    st.pop();
                } else {
                    return false;
                }
            } else if(x == ']') {
                if(!st.empty() && st.top() == '[') {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        
        if(!st.empty()) return false;
        return true;
    }
};