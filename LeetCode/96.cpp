#include <bits/stdc++.h>
using namespace std;

// Unique Binary Search Trees

class Solution {
public:
    int numTrees(int n) {
        int dp[20] = {0};
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j <= i; j++) {
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }
};

// Or use Catalan Numbers
// 
// idx  : 0 1 2 3 4  5  6   7
// C(n) : 1 1 2 5 14 42 132 439
//
// Comb(2 * n, n) / (n + 1);