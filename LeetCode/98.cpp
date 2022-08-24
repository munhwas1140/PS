#include <bits/stdc++.h>
using namespace std;

// Validate Binary Search Tree

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
    bool isValidBST(TreeNode* root) {
        vector<int> a;
        return go(root, a);         
    }
    
    bool go(TreeNode *node, vector<int> &a) {
        if(!node) return true;
        
        if(!go(node->left, a)) return false;
        if(a.empty() || a.back() < node->val) {
            a.push_back(node->val);
        } else return false;
        if(!go(node->right, a)) return false;
        return true;
    }
};