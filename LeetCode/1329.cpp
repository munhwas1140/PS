#include <bits/stdc++.h>
using namespace std;

// Sort the Matrix Diagonally

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        
        for(int i = 0; i < m; i++) {
            vector<int> tmp;
            int x = 0, y = i;
            while(x < n && y < m) { 
                tmp.push_back(mat[x][y]);
                x += 1;
                y += 1;
            }
            sort(tmp.begin(), tmp.end());
            x = 0; y = i;
            for(int k = 0; k < tmp.size(); k++) {
                ans[x+k][y+k] = tmp[k];
            }
        }
        for(int i = 1; i < n; i++) {
            vector<int> tmp;
            int x = i, y = 0;
            while(x < n && y < m) { 
                tmp.push_back(mat[x][y]);
                x += 1;
                y += 1;
            }
            sort(tmp.begin(), tmp.end());
            x = i; y = 0;
            for(int k = 0; k < tmp.size(); k++) {
                ans[x+k][y+k] = tmp[k];
            }
        }
        return ans;
    }
};