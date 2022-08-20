#include <bits/stdc++.h>
using namespace std;

// Longest Substring Without Repeating Characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> dp(n);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            dp[i] = 1;
            if(i > 0) {
                int j = 1;
                for(j = 1; j <= dp[i-1]; j++) {
                    if(s[i] == s[i - j]) {
                        break;
                    }
                }
                if(j > 1) {
                    dp[i] = j;
                }
            }
            ans = max(dp[i], ans);
        }
        return ans;
    }
};