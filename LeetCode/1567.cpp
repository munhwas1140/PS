#include <bits/stdc++.h>
using namespace std;

// Maximum Length of Subarray With Positive Product

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int l = 0, r = 0;
        int lsz = 0, rsz = 0;
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            l = (l ? l : 1) * (nums[i] > 0 ? 1 : nums[i] == 0 ? 0 : -1) ;
            lsz += 1;
            if(!l) lsz = 0;
            else if(l > 0) ans = max(ans,lsz);
            
            r = (r ? r : 1) * (nums[n-1-i] > 0 ? 1 : nums[n-1-i] == 0 ? 0 : -1);
            rsz += 1;
            if(!r) rsz = 0;
            else if(r > 0) ans = max(ans,rsz);
        }
        return ans;
    }
};