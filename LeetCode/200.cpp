#include <bits/stdc++.h>
using namespace std;

// Number of Islands 

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        int cnt = 0;
       
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1') {
                    cnt += 1;
                    grid[i][j] = '0';
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    while(!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        for(int k = 0; k < 4; k++) {
                            int nx = x + dx[k];
                            int ny = y + dy[k];
                            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                            if(grid[nx][ny] == '1') {
                                grid[nx][ny] = '0';
                                q.push({nx,ny}); 
                            } 
                           
                        }
                    }
                    
                }
            }
        }
        return cnt;
    }
};