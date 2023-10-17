#include <bits/stdc++.h>
using namespace std;

// Climbing Stairs

class Solution {
public:
    
    vector<int> dp;
    Solution() : dp(46) {}

    int climbStairs(int n) {
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};