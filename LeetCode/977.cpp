#include <bits/stdc++.h>
using namespace std;

// Squares of a Sorted Array

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int l,r,k;
        k = r = n - 1;
        l = 0;
        
        while(l <= r) {
            if(abs(nums[l]) > abs(nums[r])) {
                ans[k--] = nums[l] * nums[l];
                l += 1;
            } else {
                ans[k--] = nums[r] * nums[r];
                r -= 1;
            }
        }
        return ans;
    }
};