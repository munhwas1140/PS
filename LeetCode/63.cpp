#include <bits/stdc++.h>
using namespace std;

// Unique Paths II

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(obstacleGrid[0][0] || obstacleGrid[n-1][m-1]) return 0;
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++) {
            dp[i][0] = 1;
            if(obstacleGrid[i][0]) {
                dp[i][0] = 0;
                break;
            }
        }
        for(int i = 0; i < m; i++) {
            dp[0][i] = 1;
            if(obstacleGrid[0][i]) {
                dp[0][i] = 0;
                break;
            }
        }
            
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(obstacleGrid[i][j]) continue;
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
    }
};