#include <bits/stdc++.h>
using namespace std;

// Backspace String Compare

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> ss, tt;
        for(char x : s) {
            if(x == '#') {
                if(!ss.empty()) ss.pop();
            } else ss.push(x);
        }
        for(char x : t) {
            if(x == '#') {
                if(!tt.empty()) tt.pop();
            } else tt.push(x);
        }
        return ss == tt;
    }
};