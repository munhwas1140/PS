#include <bits/stdc++.h>
using namespace std;

// Pacific Atlantic Water Flow

class Solution {
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> ans;
        vector<vector<int>> cnt(n, vector<int>(m, 0));
        bool visited[n][m];
        memset(visited,false,sizeof(visited));
        queue<pair<int,int>> q;
        for(int i = 0; i < m; i++) {
            visited[0][i] = true;
            q.push({0,i});
        }
        for(int i = 1; i < n; i++) {
            visited[i][0] = true;
            q.push({i,0});
        }
        
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            cnt[x][y] += 1;
            
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(heights[nx][ny] >= heights[x][y] && !visited[nx][ny]) {
                    q.push({nx,ny});
                    visited[nx][ny] = true;
                }
            }
        }
        
        memset(visited,false,sizeof(visited));
        for(int i = 0; i < m; i++) {
            visited[n - 1][i] = true;
            q.push({n-1,i});
        }
        for(int i = 0; i < n - 1; i++) {
            visited[i][m-1] = true;
            q.push({i,m-1});
        }
        
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            cnt[x][y] += 1;
            
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(heights[nx][ny] >= heights[x][y] && !visited[nx][ny]) {
                    q.push({nx,ny});
                    visited[nx][ny] = true;
                }
            }
        }
       
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(cnt[i][j] == 2)  {
                    vector<int> tmp = {i, j};
                    ans.push_back(tmp);
                }
            }
        }
        return ans;
    }
};