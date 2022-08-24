#include <bits/stdc++.h>
using namespace std;

//Two Sum IV - input is a BST

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
    bool findTarget(TreeNode* root, int k) {
        vector<int> val;
        go(val, root);
        int l = 0;
        int r = val.size() - 1;
        while(l < r) {
            int x = val[l] + val[r];
            if(x < k) {
                l += 1;
            } else if(x > k) {
                r -= 1;
            } else return true;
        }
        return false;
    }
    
    void go(vector<int> &val, TreeNode *root) {
        if(!root) return ;
        
        go(val, root->left);
        val.push_back(root->val);
        go(val, root->right);
    }
};