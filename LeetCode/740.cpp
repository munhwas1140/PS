#include <bits/stdc++.h>
using namespace std;

// Delete and Earn

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int cnt[10001] = {0};
        for(int x : nums) {
            cnt[x] += 1;
        }
        vector<int> a;
        for(int i = 1; i < 10001; i++) {
            if(cnt[i]) {
                if(!cnt[i-1] && a.size() != 0) a.push_back(0);
                a.push_back(i * cnt[i]);
            }
        }
        int n = a.size();
        if(n == 1) return a[0];
        else if(n == 2) return max(a[0], a[1]);
        vector<int> dp(n);
        
        dp[0] = a[0];
        dp[1] = a[1];
        dp[2] = dp[0] + a[2];
        for(int i = 3; i < n; i++) {
            dp[i] = max(dp[i-2], dp[i-3]) + a[i];
        }
        return max(dp[n-1], dp[n-2]);
    }
};