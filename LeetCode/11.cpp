#include <bits/stdc++.h>
using namespace std;

// Container With Most Water

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n - 1;
        int lmax =  height[l], rmax = height[r];
        int ans = -1;
        while(l < r) {
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);
            ans = max(ans, (r - l) * min(lmax,rmax));
            
            if(rmax > lmax) {
                l++;
            } else r--;
        }
        return ans;
    }
};