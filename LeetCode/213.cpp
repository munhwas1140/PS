#include <bits/stdc++.h>
using namespace std;

// House Robber II

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        else if(n == 1) return nums[0];
        else if(n == 2) return max(nums[0], nums[1]);
        else if(n == 3) return max({nums[0], nums[1], nums[2]});

        int dp[n];
        return max(_rob(nums, dp, 0, n - 1), _rob(nums, dp, 1, n));
    }
    
    int _rob(vector<int> &nums, int* dp, int l, int r) {
        memset(dp,0,sizeof(dp));
        dp[l] = nums[l];
        dp[l + 1] = nums[l + 1];
        dp[l + 2] = dp[l] + nums[l + 2];
        
        for(int i = l + 3; i < r; i++) {
            dp[i] = max(dp[i - 2], dp[i - 3]) + nums[i];
        }
        return max(dp[r-1], dp[r-2]);
    }

    
};