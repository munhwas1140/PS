#include <bits/stdc++.h>
using namespace std;

// Longest Increasing Subsequence

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        for(int &v : nums) {
            auto it = lower_bound(ans.begin(), ans.end(), v);
            if(it == ans.end()) {
                ans.push_back(v);
            } else *it = v;
        }
        return ans.size();
    }
};