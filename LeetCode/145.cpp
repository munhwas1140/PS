#include <bits/stdc++.h>
using namespace std;

// Binary Tree Postorder Traversal

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        go(ans, root);
        return ans;
    }
    
    void go(vector<int> &ans, TreeNode *root) {
        if(!root) return ;
        
        go(ans, root->left);
        go(ans, root->right);
        ans.push_back(root->val);
    }
};