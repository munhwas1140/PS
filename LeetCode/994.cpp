#include <bits/stdc++.h>
using namespace std;

// Rotting Oranges

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>> q;
        vector<vector<int>> dist(n,vector<int>(m, -1));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        
        int ans = 0;
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            ans = max(ans, dist[x][y]);
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) return -1;
            }
        }
        return ans;
    }
};