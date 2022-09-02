#include <bits/stdc++.h>
using namespace std;

// Interval List Intersections

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        
        int l = 0, r = 0;
        int ls,le,rs,re;
        while(l < firstList.size() && r < secondList.size()) {
            ls = firstList[l][0]; le = firstList[l][1];
            rs = secondList[r][0]; re = secondList[r][1];
            
            if(le < rs) {
                l++; continue;
            } else if(re < ls) {
                r++; continue;
            }
            
            vector<int> tmp{ls,le,rs,re};
            sort(tmp.begin(), tmp.end());
            ans.push_back({tmp[1], tmp[2]});
            
            if(le < re) {
                l++; 
            } else if(le > re) {
                r++; 
            } else {
                l++; r++;
            }
        }
        
        return ans; 
    }
};