#include <bits/stdc++.h>
using namespace std;

// Average of Levels in Binary Tree

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        long long depthSum[10001];
        int depthSize[10001]; 
        memset(depthSum, 0, sizeof(depthSum));
        memset(depthSize, 0, sizeof(depthSize));
        go(depthSum, depthSize, root,0);
        vector<double> ans;
        for(int i = 0; i < 10001; i++) {
            if(depthSize[i] == 0) {
                ans.resize(i);
                break;
            }
        }
        for(int i = 0; i < ans.size(); i++) {
            ans[i] = depthSum[i] / (double)(depthSize[i]);
        }
        return ans;
    }
    
    void go(long long *sum, int *sz, TreeNode *node, int depth) {
        if(!node) return;
        sz[depth] += 1;
        sum[depth] += node->val;
        
        go(sum, sz, node->left, depth + 1);
        go(sum, sz, node->right, depth + 1);
    }
    
};