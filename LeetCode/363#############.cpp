#include <bits/stdc++.h>
using namespace std;

// Max Sum of Rectangle No Larger Than K

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = -1e9; 
        for(int i = 0; i < m; i++) {
            vector<int> sums(n, 0);
            for(int j = i; j < m; j++) {
                for(int k = 0; k < n; k++) {
                    sums[k] += matrix[k][j];
                }
                set<int> s;
                s.insert(0);
                int curSum = 0;
                for(int &sum : sums) {
                    curSum += sum;
                    auto it = s.lower_bound(curSum - k);
                    if(it != s.end()) ans = max(ans, curSum - *it);
                    s.insert(curSum);
                } 
            }
        }
        return ans;
    }
};