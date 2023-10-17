#include <bits/stdc++.h>
using namespace std;

// Reshape the Matrix

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size();
        int m = mat[0].size();
        if((r >= n && c >= m) || (n * m > r * c)) return mat;
        vector<vector<int>> ans(r,vector<int>(c,0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int tmp = i * m + j;
                ans[tmp/c][tmp%c] = mat[i][j];
            }
        }
        return ans;
    }
};