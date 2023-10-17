#include <bits/stdc++.h>
using namespace std;

// Jump Game II

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        
        for(int i = 0; i < n; i++) {
            for(int j = (i + nums[i]) >= n ? n - i - 1 : nums[i]; j > 0; j--) {
                if(ans[i + j] == 0 || ans[i + j] > ans[i] + 1) {
                    ans[i + j] = ans[i] + 1;
                } else {
                    break;
                }
            }
        }
        
        return ans[n-1];
    }
};