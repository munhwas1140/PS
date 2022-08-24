#include <bits/stdc++.h>
using namespace std;

// Combinations 

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> tmp;
        go(ans, n, k, 1, tmp);
        return ans;
    }
    
    void go(vector<vector<int>> &ans, int n, int k, int idx, vector<int> &tmp) {
        if(k == 0) {
            ans.push_back(tmp);
            return ;
        }
        if(idx > n) return; 
       
        for(int i = idx; i <= n; i++) {
            tmp.push_back(i);
            go(ans, n, k - 1, i + 1, tmp);
            tmp.pop_back();
        }
       
        return ;
    }
};