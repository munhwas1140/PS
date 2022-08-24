#include <bits/stdc++.h>
using namespace std;

// Word Break

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        sort(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n + 1);
        dp[0] = true;
        
        for(int i = 0; i < n; i++) {
            for(int j = 1; j <= n - i; j++) {
                if(dp[i] && find(wordDict.begin(), wordDict.end(), s.substr(i,j)) != wordDict.end()) {
                    dp[i + j] = true;
                } 
            }
        }
        return dp[n];
        
    }
};