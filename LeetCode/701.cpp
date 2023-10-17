#include <bits/stdc++.h>
using namespace std;

// Insert into a Binary Search Tree

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return insert(root, val);
    }
    
    TreeNode *insert(TreeNode *root, int val) {
        if(!root) {
            TreeNode *node = new TreeNode(val);
            return node;
        }
        
        if(val < root->val) {
            root->left = insert(root->left, val);
        } else if(val > root->val) {
            root->right = insert(root->right, val);
        }
        
        return root;
    }
};