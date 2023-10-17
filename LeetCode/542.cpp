#include <bits/stdc++.h>
using namespace std;

// 01 Matrix

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) q.push({i, j});
                else mat[i][j] = -1;
            }
        }
        
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m || mat[nx][ny] != -1) continue;
                mat[nx][ny] = mat[x][y] + 1;
                q.push({nx,ny});
            }
        }
        return mat;
    }
};