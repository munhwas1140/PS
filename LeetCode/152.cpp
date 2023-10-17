#include <bits/stdc++.h>
using namespace std;

// Maximum Product SubArray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int l = 0, r = 0;
        for(int i = 0; i < n; i++) { 
            l = (l ? l : 1) * nums[i];
            r = (r ? r : 1) * nums[n - 1 - i];
            ans = max({ans, l, r});
        }
        return ans;
    }
};