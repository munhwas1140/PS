#include <bits/stdc++.h>
using namespace std;

// Arithmetic Slices

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int diff = 1e9;
        long long ans = 0;
        long long num = 0;
        int cnt = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(diff == 1e9) {
                diff = nums[i] - nums[i-1]; 
                cnt = 2;
            } else if(diff == (nums[i] - nums[i-1])) {
                cnt += 1;
            } else {
                num = 0;
                cnt = 2;
                diff = nums[i] - nums[i-1];
            }
            if(cnt >= 3) {
                num += 1;
                ans += num;
            }
        }
        return ans; 
    }
};