#include <bits/stdc++.h>
using namespace std;

// Leter Case Permutation

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        go(ans,s,0);
        return ans;
    }
    
    void go(vector<string> &ans, string &s, int idx) {
        if(idx == s.size()) {
            ans.push_back(s);
            return ;
        }
        
        go(ans, s, idx + 1);
        if('a' <= s[idx] && s[idx] <= 'z') {
            s[idx] -= 32;
            go(ans, s, idx + 1);
        } else if('A' <= s[idx] && s[idx] <= 'Z') {
            s[idx] += 32;
            go(ans, s, idx + 1);
        }
        return ;
    }
};