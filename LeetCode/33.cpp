#include <bits/stdc++.h>
using namespace std;

// Search in Rotated Sorted Array

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = nums.size() - 1;
        int tmp = 0;
        while(l <= r) {
            int m = (l + r) / 2;
            if(nums[tmp] > nums[m]) {
                tmp = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        
        auto a = find(nums.begin() + l, nums.end(), target);
        auto b = find(nums.begin(),  nums.begin() + l, target);
        if(a != nums.end()) return a - nums.begin();
        if(b != nums.begin() + l) return b - nums.begin();
        return -1;
    }
};