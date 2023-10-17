#include <bits/stdc++.h>
using namespace std;

// Count Good Nodes in Binary Tree

Definition for a binary tree node.
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
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int start = root->val;
        return go(root,start);
    }
    
    int go(TreeNode *now, int prev) {
        if(!now) return 0;
        
        int ret = 0;
        if(prev <= now->val) ret += 1;
        ret += go(now->left, max(prev,now->val));
        ret += go(now->right, max(prev, now->val));
        return ret;
        
    }
};