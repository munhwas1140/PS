#include <bits/stdc++.h>
using namespace std;

// Binary Tree Level Order Traversal

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        go(ans, root, 0);
        return ans;
    }
    
    void go(vector<vector<int>> &ans, TreeNode *root, int depth) {
        if(!root) return ;
        
        if(ans.size() <= depth) {
            ans.push_back(vector<int>());
        }
        ans[depth].push_back(root->val);
        go(ans, root->left, depth + 1);
        go(ans, root->right, depth + 1);
    }
};