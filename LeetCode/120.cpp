#include <bits/stdc++.h>
using namespace std;

// Triangle

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp = triangle;
        int n = triangle.size();
        for(int i = 1; i < n; i++) {
            dp[i][0] = dp[i-1][0] + triangle[i][0];
            dp[i][i] = dp[i-1][i-1] + triangle[i][i];
            for(int j = 1; j < i; j++) {
                dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
            }
        }
    
        int ans = 1e5;
        for(int i = 0; i < n; i++) {
           ans = min(ans, dp[n-1][i]); 
        }
        return ans;
    }
};