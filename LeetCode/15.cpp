#include <bits/stdc++.h>
using namespace std;

// 3Sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int target = -nums[i];
            int l = i + 1;
            int r = n - 1;
            while(l < r) {
                int sum = nums[l] + nums[r];
                if(sum < target) l++;
                else if(sum > target) r--;
                else {
                    ans.push_back(vector<int>{nums[i],nums[l],nums[r]});
                    while(l < r && nums[l] == nums[l+1]) l++;
                    while(l < r && nums[r] == nums[r-1]) r--;
                    l++;
                    r--;
                }
            }
        }
        return ans;
    }
};