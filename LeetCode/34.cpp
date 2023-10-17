#include <bits/stdc++.h>
using namespace std;

// Find First and Last Position of Element in Sorted Array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        auto lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        auto ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(lb == ub) {
            return vector<int>(2, -1);
        } else {
            vector<int> tmp = {(int)lb, (int)ub - 1};
            return tmp;
        }
    }
};