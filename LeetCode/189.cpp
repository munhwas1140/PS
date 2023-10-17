#include <bits/stdc++.h>

using namespace std;

// Rotate Array

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        for(int i = 0; i < n / 2; i++) {
            swap(nums[i], nums[n - 1 - i]);
        }
        
        for(int i = 0; i < k / 2; i++) {
            swap(nums[i], nums[k - 1 - i]);    
        }
        
        for(int i = 0; i < (n - k) / 2; i++) {
            swap(nums[i + k], nums[n - 1 - i]);
        }
    }
};