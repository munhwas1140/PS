#include <bits/stdc++.h>
using namespace std;

// Flood Fill



class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int key = image[sr][sc];
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        
        if(key == color) return image;
        
        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc] = color;
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(image[nx][ny] == key) {
                    image[nx][ny] = color;
                    q.push({nx,ny});
                }
            }
        }
        
        return image;
    }
};