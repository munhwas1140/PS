#include <bits/stdc++.h>
using namespace std;

// Maximum Sum Circular Subarray

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int minsum, minans, maxsum, maxans, sum;
        minsum = minans = maxsum = maxans = sum = nums[0];

        for(int i = 1; i < n; i++) {
            sum += nums[i];
            minsum = min(minsum + nums[i], nums[i]);
            maxsum = max(maxsum + nums[i], nums[i]);
            maxans = max(maxans, maxsum);
            minans = min(minans, minsum);
        }
        
        return maxans > 0 ? max(maxans, sum - minans) : maxans;
    }
};