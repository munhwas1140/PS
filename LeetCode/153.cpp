#include <bits/stdc++.h>
using namespace std;

// Find Minimum in Rotated Sorted Array

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int m;
        int tmp = nums[0]; 
        while(l <= r) {
            m = (l + r) / 2;
            if(nums[m] < tmp) {
                r = m - 1;
                tmp = nums[m];
            } else {
                l = m + 1;
            }
        }
        return tmp;
    }
};