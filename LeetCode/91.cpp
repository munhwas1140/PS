#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return go(dp, s,0);
    }
    
    int go(vector<int> &dp, string &s, int idx) {
        if(idx == s.size()) return 1;
        if(s[idx] == '0') return 0;
        
        int &ret = dp[idx];
        if(ret != -1) return ret;
        
        ret = 0;
        
        ret += go(dp, s,idx + 1);
        if(idx < s.size() - 1 && (s[idx] == '1' || (s[idx] == '2' && s[idx + 1] <= '6'))) {
            ret += go(dp, s ,idx + 2);
        }
        return ret;
    }
};