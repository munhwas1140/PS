#include <bits/stdc++.h>
using namespace std;

// Symmetric Tree

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
    bool isSymmetric(TreeNode* root) {
        if(!root) return false;
        return check(root->left, root->right);
    }
    
    bool check(TreeNode *a, TreeNode *b) {
        if(a && !b) return false;
        if(!a && b) return false;
        if(!a && !b) return true;
        if(a->val != b->val) return false;
        if(!check(a->left, b->right)) return false;
        if(!check(a->right, b->left)) return false;
        return true;
    }
};