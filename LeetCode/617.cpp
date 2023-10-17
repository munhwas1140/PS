#include <bits/stdc++.h>
using namespace std;

// Merge Two Binary Trees

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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1) return root2;
        if(!root2) return root1;
        go(root1, root2);
        return root1;
    }
    
    void go(TreeNode *a, TreeNode *b) {
        a->val += b->val;
        if(a->left && b->left) {
            go(a->left, b->left);    
        }
        if(a->right && b->right) {
            go(a->right, b->right);
        }
        if(!a->left) a->left = b->left;
        if(!a->right) a->right = b->right;
    }
};