#include <bits/stdc++.h>
using namespace std;

// Longest Palindromic Subsequence

//memo

// class Solution {
// public:
//     int wiggleMaxLength(vector<int>& nums) {
//         int n = nums.size();
        
//         vector<int> up(n, 0);
//         vector<int> down(n, 0);
        
//         up[0] = down[0] = 1;
//         for(int i = 1; i < n; i++) {
//             if(nums[i] > nums[i-1]) {
//                 up[i] = down[i-1] + 1;
//                 down[i] = down[i-1];
//             } else if(nums[i] < nums[i-1]) {
//                 down[i] = up[i-1] + 1;
//                 up[i] = up[i-1];
//             } else {
//                 down[i] = down[i-1];
//                 up[i] = up[i-1];
//             }
//         }
       
//         return max(down[n-1], up[n-1]);
//     }
// };


// dp

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n ,0));
        // dp[size][start idx];
        
        for(int i = 0; i < n; i++) dp[1][i] = 1;
        for(int sz = 2; sz <= n; sz++) {
            for(int j = 0; j <= n - sz; j++) {
                if(s[j] == s[j + sz - 1]) {
                    dp[sz][j] = 2 + dp[sz - 2][j + 1];
                } else {
                    dp[sz][j] = max(dp[sz-1][j+1], dp[sz-1][j]);
                }
            }
        }
        return dp[n][0];
    }
};